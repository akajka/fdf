/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:22:28 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/17 12:44:58 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		prog_exit(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
	exit(0);
	return (0);
}

int		print_error(int error_code)
{
	if (error_code == 0)
		ft_putendl("USAGE: ./fdf [map]");
	if (error_code == 1)
		ft_putendl("File is not valid");
	if (error_code == 2)
		ft_putendl("MLX error");
	if (error_code == 3)
		ft_putendl("Every line must contains the same amount of elements");
	if (error_code == 4)
		ft_putendl("The map is too small");
	if (error_code == 6)
		ft_putendl("Malloc error");
	return (0);
}
