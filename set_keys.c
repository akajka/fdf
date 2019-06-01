/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:09 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/16 18:19:12 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		set_keys(int keycode, t_fdf *fdf)
{
	if (keycode == 123)
		fdf->trans.mov.x -= MOVE;
	if (keycode == 124)
		fdf->trans.mov.x += MOVE;
	if (keycode == 126)
		fdf->trans.mov.y -= MOVE;
	if (keycode == 125)
		fdf->trans.mov.y += MOVE;
	if (keycode == 35)
		fdf->trans.rotate = new_vec3f(0, 0, 0, 0);
	if (keycode == 34)
		fdf->trans.rotate = new_vec3f(45, 0, 60, 0);
	if (keycode == 15)
		set_defaults(fdf);
	return (0);
}

int		set_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == ROT_X_RIGHT)
		fdf->trans.rotate.x += ROT_SPEED;
	if (keycode == ROT_X_LEFT)
		fdf->trans.rotate.x -= ROT_SPEED;
	if (keycode == ROT_Y_UP)
		fdf->trans.rotate.y += ROT_SPEED;
	if (keycode == ROT_Y_DOWN)
		fdf->trans.rotate.y -= ROT_SPEED;
	if (keycode == ROT_Z_RIGHT)
		fdf->trans.rotate.z += ROT_SPEED;
	if (keycode == ROT_Z_LEFT)
		fdf->trans.rotate.z -= ROT_SPEED;
	return (0);
}

int		set_zoom_and_depth(int keycode, t_fdf *fdf)
{
	if (keycode == 40)
		fdf->trans.depth += ALTITUDE_SPEED;
	if (keycode == 38)
		fdf->trans.depth -= ALTITUDE_SPEED;
	if (keycode == 78 || keycode == 27)
		fdf->trans.zoom -= 0.5;
	if (keycode == 69 || keycode == 24)
		fdf->trans.zoom += 0.5;
	fdf->trans.zoom = CLAMP(fdf->trans.zoom, 0.5, 200);
	return (0);
}
