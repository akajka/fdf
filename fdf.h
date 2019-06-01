/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnovikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:22:18 by nnovikov          #+#    #+#             */
/*   Updated: 2019/03/29 13:22:22 by nnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

# define WIDTH 1300
# define HEIGHT 900
# define MOVE 10
# define ROT_SPEED 5
# define ALTITUDE_SPEED 0.01
# define CLAMP(x, low, high) (((x)>(high))?(high):(((x)<(low))?(low):(x)))
# define RO(X) ((int)(((double)(X))+0.5))
# define F(X) (((double)(X))-(double)I(X))
# define R(X) (1.0-F(X))
# define I(X) ((int)(X))

# define EXIT 53
# define ROT_Z_LEFT 0
# define ROT_Z_RIGHT 2
# define ROT_Y_UP 12
# define ROT_Y_DOWN 14
# define ROT_X_RIGHT 1
# define ROT_X_LEFT 13
# define ENTER 36

# define GRAY 0xBEBEBE

typedef struct	s_2d
{
	int			x;
	int			y;
}				t_2d;

typedef	struct	s_2f
{
	double		x;
	double		y;
}				t_2f;

typedef struct	s_line
{
	t_2f		delta;
	t_2f		end;
	t_2f		inter;
	double		gradient;
}				t_line;

typedef struct	s_3d
{
	int			x;
	int			y;
	int			z;
	int			hex_col;
}				t_3d;

typedef struct	s_3df {
	double		x;
	double		y;
	double		z;
	int			draw;
}				t_3df;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		*img_string;
	int			endian;
	int			line_size;
	int			bpp;
}				t_mlx;

typedef struct	s_trans
{
	t_3df		rotate;
	t_3df		mov;
	float		zoom;
	float		zoom_y;
	float		depth;
}				t_trans;

typedef struct	s_fdf
{
	char		*map_name;
	int			draw;
	int			color;
	int			color1;
	t_mlx		mlx;
	t_3d		**points;
	t_2d		map_len;
	int			min_z;
	int			max_z;
	t_line		line;
	t_trans		trans;
	void		*img_figure;
	int			m_heigth;
	int			m_width;
}				t_fdf;

int				ft_atoi_base(const char *from, int base);

void			draw_line(t_fdf *fdf, t_2d p1, t_2d p2);

int				prog_exit(t_fdf *fdf);

int				print_error(int error_code);

int				check_map_name(char *arg);

int				set_defaults(t_fdf *fdf);

int				count_len_x(t_fdf *fdf, char *line, int not_first_line);

int				count_len_y(t_fdf *fdf, int fd);

int				addition(int keycode);

int				parse_manager(t_fdf *fdf);

int				parse_line(t_fdf *fdf, char *line, int n);

int				parse(t_fdf *fdf, int fd);

int				define_points(t_fdf *fdf, int i, int n, char **lines);

void			render_this_frame(t_fdf *fdf);

void			rotate_x(t_3df *v, double ang);

void			rotate_y(t_3df *v, double ang);

void			rotate_z(t_3df *v, double ang);

int				set_zoom_and_depth(int keycode, t_fdf *fdf);

int				set_rotation(int keycode, t_fdf *fdf);

int				set_keys(int keycode, t_fdf *fdf);

t_2d			new_2(int x, int y);

void			swap_color(t_fdf *fdf);

t_3df			new_vec3f(double x, double y, double z, int color);

t_3df			v3f_scale(t_3df v, double scaler);

#endif
