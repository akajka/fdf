/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:41:45 by nnovikov          #+#    #+#             */
/*   Updated: 2019/04/16 17:41:53 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_len_x(t_fdf *fdf, char *line, int not_first_line)
{
	int		i;
	int		temp_len;

	i = 0;
	temp_len = 0;
	while (line[i] == ' ')
		i++;
	while (line[i + 1])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
			temp_len++;
		i++;
	}
	temp_len++;
	if (not_first_line && temp_len != fdf->map_len.x)
		return (print_error(3));
	fdf->map_len.x = temp_len;
	return (1);
}

int		count_len_y(t_fdf *fdf, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(count_len_x(fdf, line, i)))
			return (0);
		if (line)
			free(line);
		i++;
		fdf->map_len.y++;
	}
	return (1);
}

void	color_high(t_fdf *fdf, int j, int i)
{
	if (fdf->points[j][i].z >= 5 && fdf->points[j][i].z < 15)
		fdf->points[j][i].hex_col = 0x5F8702;
	if (fdf->points[j][i].z >= 15 && fdf->points[j][i].z < 25)
		fdf->points[j][i].hex_col = 0xB4D003;
	if (fdf->points[j][i].z >= 25 && fdf->points[j][i].z < 40)
		fdf->points[j][i].hex_col = 0xE3F300;
	if (fdf->points[j][i].z >= 40 && fdf->points[j][i].z < 55)
		fdf->points[j][i].hex_col = 0xFFEF04;
	if (fdf->points[j][i].z >= 55 && fdf->points[j][i].z < 60)
		fdf->points[j][i].hex_col = 0xFFCD00;
	if (fdf->points[j][i].z >= 60 && fdf->points[j][i].z < 80)
		fdf->points[j][i].hex_col = 0xE28101;
	if (fdf->points[j][i].z >= 80)
		fdf->points[j][i].hex_col = 0xDC7B1A;
}

void	color_low(t_fdf *fdf, int j, int i)
{
	if (fdf->points[j][i].z >= -5 && fdf->points[j][i].z < 5)
		fdf->points[j][i].hex_col = 0x005409;
	if (fdf->points[j][i].z < -5 && fdf->points[j][i].z >= -15)
		fdf->points[j][i].hex_col = 0x048164;
	if (fdf->points[j][i].z < -15 && fdf->points[j][i].z >= -25)
		fdf->points[j][i].hex_col = 0x00B09F;
	if (fdf->points[j][i].z < -25 && fdf->points[j][i].z >= -40)
		fdf->points[j][i].hex_col = 0x008DB0;
	if (fdf->points[j][i].z < -40 && fdf->points[j][i].z >= -55)
		fdf->points[j][i].hex_col = 0x2B65DB;
	if (fdf->points[j][i].z < -55 && fdf->points[j][i].z >= -60)
		fdf->points[j][i].hex_col = 0x0048D7;
	if (fdf->points[j][i].z < -60 && fdf->points[j][i].z >= -80)
		fdf->points[j][i].hex_col = 0x3542FC;
	if (fdf->points[j][i].z < -80)
		fdf->points[j][i].hex_col = 0x3C41DB;
}

int		define_points(t_fdf *fdf, int i, int j, char **lines)
{
	char	**split;

	fdf->points[j][i].x = i;
	fdf->points[j][i].y = j;
	fdf->points[j][i].z = CLAMP(ft_atoi(lines[i]), -500, 500);
	fdf->points[j][i].hex_col = 0;
	if (is_char_there(lines[i], ','))
	{
		if (!(split = ft_strsplit(lines[i], ',')))
			return (print_error(6));
		fdf->points[j][i].hex_col = ft_atoi_base(split[1], 16);
		free(split[0]);
		free(split[1]);
		free(split);
	}
	else
	{
		color_high(fdf, j, i);
		color_low(fdf, j, i);
	}
	free(lines[i]);
	return (0);
}
