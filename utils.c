/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:20:04 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/05 15:10:27 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3df	v3f_scale(t_3df v, double scaler)
{
	t_3df result;

	result.x = v.x * scaler;
	result.y = v.y * scaler;
	result.z = v.z * scaler;
	return (result);
}

t_3df	new_vec3f(double x, double y, double z, int color)
{
	t_3df v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.draw = color;
	return (v);
}

t_2d	new_2(int x, int y)
{
	t_2d v;

	v.x = x;
	v.y = y;
	return (v);
}

void	swap_color(t_fdf *fdf)
{
	int		tmp;

	tmp = fdf->color;
	fdf->color = fdf->color1;
	fdf->color1 = tmp;
}
