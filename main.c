/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:21:16 by nnovikov          #+#    #+#             */
/*   Updated: 2019/05/31 16:20:53 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 15,
									GRAY, "enter  pls don't do it");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 40, GRAY, ">      right");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 65,
									GRAY, "<      left");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 90,
									GRAY, "^      up");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 115,
									GRAY, "down   move");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 140,
									GRAY, "q e    rotate z");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 165,
									GRAY, "w s    rotate x");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 190,
									GRAY, "a d    rotate y");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 215,
									GRAY, "+ -    zoom");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 240,
									GRAY, "j k    high hopes");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 265,
									GRAY, "i      iso");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 290,
									GRAY, "p      paralel");
	mlx_string_put(fdf->mlx.init, fdf->mlx.win, 25, 315,
									GRAY, "r      reset");
}

int		check_map_name(char *arg)
{
	int		check;
	int		fd;
	char	*buff[16];

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (0);
	if (!(check = read(fd, buff, 16)))
		return (0);
	if (check < 8)
		return (0);
	return (1);
}

int		set_defaults(t_fdf *fdf)
{
	if (!(fdf->mlx.img_string = mlx_get_data_addr(fdf->mlx.img,
		&fdf->mlx.bpp, &fdf->mlx.line_size, &fdf->mlx.endian)))
		return (0);
	fdf->trans.rotate = new_vec3f(0, 0, 0, 0);
	fdf->trans.zoom = WIDTH / (2 * fdf->map_len.x);
	fdf->trans.zoom_y = HEIGHT / (2 * fdf->map_len.y);
	fdf->trans.mov = new_vec3f(fdf->map_len.x / 2 * fdf->trans.zoom + WIDTH
		/ 4 + 70, fdf->map_len.y / 2 * fdf->trans.zoom_y + HEIGHT / 4, 0, 0);
	fdf->trans.depth = 0.4;
	render_this_frame(fdf);
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	display_menu(fdf);
	return (1);
}

int		listen_keys_and_render_frame(int keycode, t_fdf *fdf)
{
	if (keycode == EXIT)
		prog_exit(fdf);
	set_keys(keycode, fdf);
	set_rotation(keycode, fdf);
	set_zoom_and_depth(keycode, fdf);
	addition(keycode);
	ft_bzero(fdf->mlx.img_string, (WIDTH * HEIGHT * 4));
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	render_this_frame(fdf);
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	display_menu(fdf);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf fdf;

	if (argc != 2)
		return (print_error(0));
	if (!check_map_name(argv[1]))
		return (print_error(1));
	fdf.map_name = argv[1];
	fdf.mlx.init = mlx_init();
	if (!(fdf.mlx.win = mlx_new_window(fdf.mlx.init, WIDTH, HEIGHT,
					fdf.map_name)))
		return (print_error(6));
	if (!(fdf.mlx.img = mlx_new_image(fdf.mlx.init, WIDTH, HEIGHT)))
		return (print_error(6));
	if (!parse_manager(&fdf))
		return (print_error(6));
	if (!set_defaults(&fdf))
		return (print_error(2));
	mlx_hook(fdf.mlx.win, 2, 0, listen_keys_and_render_frame, &fdf);
	mlx_hook(fdf.mlx.win, 17, 0, prog_exit, &fdf);
	mlx_loop(fdf.mlx.init);
}
