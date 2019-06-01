/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:58 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/16 18:20:06 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_3df *v, double ang)
{
	double tmp;

	ang = ang * M_PI / 180.0;
	tmp = v->y;
	v->y = v->y * cos(ang) - v->z * sin(ang);
	v->z = tmp * sin(ang) + v->z * cos(ang);
}

void	rotate_y(t_3df *v, double ang)
{
	double tmp;

	ang = ang * M_PI / 180.0;
	tmp = v->z;
	v->z = v->z * cos(ang) - v->x * sin(ang);
	v->x = tmp * sin(ang) + v->x * cos(ang);
}

void	rotate_z(t_3df *v, double ang)
{
	double tmp;

	ang = ang * M_PI / 180.0;
	tmp = v->x;
	v->x = v->x * cos(ang) - v->y * sin(ang);
	v->y = tmp * sin(ang) + v->y * cos(ang);
}
