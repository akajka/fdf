/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:21:06 by nnovikov          #+#    #+#             */
/*   Updated: 2019/03/29 13:21:09 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		parse_line(t_fdf *fdf, char *line, int n)
{
	int		i;
	char	**lines;

	i = 0;
	if (!(fdf->points[n] = (t_3d*)malloc(sizeof(t_3d) * fdf->map_len.x)))
		return (0);
	if (!(lines = ft_strsplit(line, ' ')))
		return (0);
	while (i < fdf->map_len.x)
	{
		if (lines[i])
			define_points(fdf, i, n, lines);
		i++;
	}
	free(lines);
	return (1);
}

int		parse(t_fdf *fdf, int fd)
{
	int		n;
	char	*line;

	n = 0;
	if (!(fdf->points = (t_3d**)malloc(sizeof(t_3d*)
		* fdf->map_len.y)))
		return (0);
	while (n < fdf->map_len.y)
	{
		get_next_line(fd, &line);
		if (!(parse_line(fdf, line, n)))
			return (0);
		if (line)
			free(line);
		n++;
	}
	return (1);
}

int		parse_manager(t_fdf *fdf)
{
	int		fd;

	fdf->map_len.x = 0;
	fdf->map_len.y = 0;
	if (!(fd = open(fdf->map_name, O_RDONLY)))
		return (0);
	if (!(count_len_y(fdf, fd)))
		return (0);
	if (fdf->map_len.x < 2 || fdf->map_len.y < 2)
		return (print_error(4));
	close(fd);
	if (!(fd = open(fdf->map_name, O_RDONLY)))
		return (0);
	if (!parse(fdf, fd))
		return (0);
	close(fd);
	return (1);
}
