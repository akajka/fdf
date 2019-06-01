/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:56:21 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/16 17:56:38 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(t_fdf *fdf, t_2d p, float br)
{
	int red;
	int green;
	int blue;

	if (br > 1.0)
		br = 1.0;
	red = br * ((fdf->draw >> 16) & 0xFF);
	green = br * ((fdf->draw >> 8) & 0xFF);
	blue = br * (fdf->draw & 0xFF);
	if (p.x > 5 && p.x < WIDTH - 4 && p.y > 5 && p.y < HEIGHT - 4)
		*(int*)(fdf->mlx.img_string + (p.x + p.y * WIDTH) * 4) =
									(red << 16 | green << 8 | blue);
}

int		gradientt(int color, int color1, double percent)
{
	double	inv_percent;
	int		red;
	int		green;
	int		blue;

	if (percent > 1.0)
		percent = 1.0;
	inv_percent = 1 - percent;
	red = ((color >> 16) & 0xFF) * inv_percent + ((color1 >> 16) & 0xFF)
			* percent;
	green = ((color >> 8) & 0xFF) * inv_percent + ((color1 >> 8) & 0xFF)
			* percent;
	blue = (color & 0xFF) * inv_percent + (color1 & 0xFF) * percent;
	return (red << 16 | green << 8 | blue);
}

void	draw_horizontal_line(t_fdf *fdf, t_2d p1, t_2d p2)
{
	int		x;
	t_line	l;
	double	iter;
	double	percent;

	percent = 0;
	l = fdf->line;
	l.gradient = l.delta.y / l.delta.x;
	l.end.y = p1.y + l.gradient * (RO(p1.x) - p1.x);
	plot(fdf, new_2(RO(p1.x), I(l.end.y)), R(l.end.y) * R(p1.x + 0.5));
	plot(fdf, new_2(RO(p1.x), I(l.end.y) + 1), F(l.end.y) * R(p1.x + 0.5));
	l.inter.y = l.end.y + l.gradient;
	l.end.y = p2.y + l.gradient * (RO(p2.x) - p2.x);
	plot(fdf, new_2(RO(p2.x), I(l.end.y)), R(l.end.y) * F(p2.x + 0.5));
	plot(fdf, new_2(RO(p2.x), I(l.end.y) + 1), F(l.end.y) * F(p2.x + 0.5));
	x = RO(p1.x);
	iter = 1 / (double)(RO(p2.x) - 1 - x);
	while (++x < RO(p2.x))
	{
		fdf->draw = gradientt(fdf->color, fdf->color1, percent);
		percent += iter;
		plot(fdf, new_2(x, I(l.inter.y)), R(l.inter.y));
		plot(fdf, new_2(x, I(l.inter.y) + 1), F(l.inter.y));
		l.inter.y += l.gradient;
	}
}

void	draw_vertical_line(t_fdf *fdf, t_2d p1, t_2d p2)
{
	int		y;
	t_line	l;
	double	iter;
	double	percent;

	percent = 0;
	l = fdf->line;
	l.gradient = l.delta.x / l.delta.y;
	l.end.x = p1.x + l.gradient * (RO(p1.y) - p1.y);
	plot(fdf, new_2(I(l.end.x), RO(p1.y)), R(l.end.x) * R(p1.y + 0.5));
	plot(fdf, new_2(I(l.end.x) + 1, RO(p1.y)), F(l.end.x) * R(p1.y + 0.5));
	l.inter.x = l.end.x + l.gradient;
	l.end.x = p2.x + l.gradient * (RO(p2.y) - p2.y);
	plot(fdf, new_2(I(l.end.x), RO(p2.y)), R(l.end.x) * F(p2.y + 0.5));
	plot(fdf, new_2(I(l.end.x) + 1, RO(p2.y)), R(l.end.x) * F(p2.y + 0.5));
	y = RO(p1.y);
	iter = 1 / (double)(RO(p2.y) - 1 - y);
	while (++y < RO(p2.y))
	{
		fdf->draw = gradientt(fdf->color, fdf->color1, percent);
		percent += iter;
		plot(fdf, new_2(I(l.inter.x), y), R(l.inter.x));
		plot(fdf, new_2(I(l.inter.x) + 1, y), F(l.inter.x));
		l.inter.x += l.gradient;
	}
}

void	draw_line(t_fdf *fdf, t_2d p1, t_2d p2)
{
	fdf->line.delta.x = (double)p2.x - (double)p1.x;
	fdf->line.delta.y = (double)p2.y - (double)p1.y;
	if (ft_abs(fdf->line.delta.x) > ft_abs(fdf->line.delta.y))
	{
		if (p2.x < p1.x)
		{
			swap(&p1.x, &p2.x);
			swap(&p1.y, &p2.y);
			swap_color(fdf);
		}
		draw_horizontal_line(fdf, p1, p2);
	}
	else
	{
		if (p2.y < p1.y)
		{
			swap(&p1.x, &p2.x);
			swap(&p1.y, &p2.y);
			swap_color(fdf);
		}
		draw_vertical_line(fdf, p1, p2);
	}
}
