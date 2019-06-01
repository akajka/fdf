/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meme.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:29:19 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/05 14:36:15 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		show_cat(t_fdf *meme)
{
	if (!(meme->mlx.img = mlx_xpm_file_to_image(meme->mlx.init,
			"images/cropped_cry.XPM", &meme->m_width, &meme->m_heigth)))
		return (print_error(2));
	ft_bzero(meme->mlx.img_string, (meme->m_width * meme->m_heigth * 4));
	mlx_destroy_image(meme->mlx.init, meme->mlx.img);
	mlx_clear_window(meme->mlx.init, meme->mlx.win);
	mlx_put_image_to_window(meme->mlx.init, meme->mlx.win, meme->mlx.img, 0, 0);
	return (0);
}

int		show_doge(t_fdf *meme)
{
	if (!(meme->mlx.img = mlx_xpm_file_to_image(meme->mlx.init,
			"images/doge.XPM", &meme->m_width, &meme->m_heigth)))
		return (print_error(2));
	ft_bzero(meme->mlx.img_string, (meme->m_width * meme->m_heigth * 4));
	mlx_destroy_image(meme->mlx.init, meme->mlx.img);
	mlx_clear_window(meme->mlx.init, meme->mlx.win);
	mlx_put_image_to_window(meme->mlx.init, meme->mlx.win, meme->mlx.img, 0, 0);
	return (0);
}

int		listen_meme(int keycode, t_fdf *meme)
{
	mlx_put_image_to_window(meme->mlx.init, meme->mlx.win, meme->mlx.img, 0, 0);
	show_cat(meme);
	if (keycode == 2)
		show_doge(meme);
	mlx_string_put(meme->mlx.init, meme->mlx.win, 130, 552,
									GRAY, "press D to see Doge");
	ft_bzero(meme->mlx.img_string, (meme->m_width * meme->m_heigth * 4));
	return (0);
}

int		addition(int keycode)
{
	t_fdf	meme;

	meme.m_width = 540;
	meme.m_heigth = 580;
	if (keycode == ENTER)
	{
		meme.mlx.init = mlx_init();
		meme.mlx.win = mlx_new_window(meme.mlx.init, meme.m_width,
													meme.m_heigth, "meme");
		meme.mlx.img = mlx_new_image(meme.mlx.init, meme.m_width,
													meme.m_heigth);
		meme.mlx.img_string = mlx_get_data_addr(meme.mlx.img,
				&meme.mlx.bpp, &meme.mlx.line_size, &meme.mlx.endian);
		mlx_string_put(meme.mlx.init, meme.mlx.win, 120, 200, GRAY,
										"Instagram: s[he] be[lie]ve[d]");
		mlx_string_put(meme.mlx.init, meme.mlx.win, 200, 240, GRAY,
										"14 yr old:");
		mlx_hook(meme.mlx.win, 2, 0, listen_meme, &meme);
		mlx_loop(meme.mlx.init);
	}
	return (0);
}
