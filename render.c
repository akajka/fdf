/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:20:39 by nnovikov          #+#    #+#             */
/*   Updated: 2019/03/29 13:20:42 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	linear_trans(t_3df *p, t_trans trans, t_3df axis)
{
	p->x -= axis.x;
	p->y -= axis.y;
	p->z *= trans.depth;
	rotate_y(p, trans.rotate.y);
	rotate_z(p, trans.rotate.z);
	rotate_x(p, trans.rotate.x);
	p->x *= trans.zoom;
	p->y *= trans.zoom;
	p->x += axis.x;
	p->y += axis.y;
	p->x += trans.mov.x;
	p->y += trans.mov.y;
}

void	render_horizontal(t_fdf *fdf, int j, int i)
{
	t_3df	p1;
	t_3df	p2;
	t_2d	p_p1;
	t_2d	p_p2;
	t_3df	rotation_axis;

	p1 = new_vec3f(fdf->points[j][i].x, fdf->points[j][i].y,
					fdf->points[j][i].z, fdf->points[j][i].hex_col);
	p2 = new_vec3f(fdf->points[j][i + 1].x, fdf->points[j][i + 1].y,
					fdf->points[j][i + 1].z, fdf->points[j][i + 1].hex_col);
	rotation_axis = v3f_scale(new_vec3f(fdf->map_len.x,
					fdf->map_len.y, 0, 0), 0.5);
	linear_trans(&p1, fdf->trans, rotation_axis);
	linear_trans(&p2, fdf->trans, rotation_axis);
	p_p1.x = p1.x;
	p_p1.y = p1.y;
	p_p2.x = p2.x;
	p_p2.y = p2.y;
	fdf->draw = p1.draw;
	fdf->color = p1.draw;
	fdf->color1 = p2.draw;
	draw_line(fdf, p_p1, p_p2);
}

void	render_vertical(t_fdf *fdf, int j, int i)
{
	t_3df	p1;
	t_3df	p2;
	t_2d	p_p1;
	t_2d	p_p2;
	t_3df	rotation_axis;

	p1 = new_vec3f(fdf->points[j][i].x, fdf->points[j][i].y,
					fdf->points[j][i].z, fdf->points[j][i].hex_col);
	p2 = new_vec3f(fdf->points[j + 1][i].x, fdf->points[j + 1][i].y,
					fdf->points[j + 1][i].z, fdf->points[j + 1][i].hex_col);
	rotation_axis = v3f_scale(new_vec3f(fdf->map_len.x,
					fdf->map_len.y, 0, 0), 0.5);
	linear_trans(&p1, fdf->trans, rotation_axis);
	linear_trans(&p2, fdf->trans, rotation_axis);
	p_p1.x = p1.x;
	p_p1.y = p1.y;
	p_p2.x = p2.x;
	p_p2.y = p2.y;
	fdf->draw = p1.draw;
	fdf->color = p1.draw;
	fdf->color1 = p2.draw;
	draw_line(fdf, p_p1, p_p2);
}

void	render_this_frame(t_fdf *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (j < fdf->map_len.y)
	{
		i = 0;
		while (i < fdf->map_len.x)
		{
			if (i < fdf->map_len.x - 1)
				render_horizontal(fdf, j, i);
			if (j < fdf->map_len.y - 1)
				render_vertical(fdf, j, i);
			i++;
		}
		j++;
	}
}
