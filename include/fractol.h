/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:34:19 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/29 11:55:21 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

# define HEIGHT	200
# define WIDTH	200
# define LOOP	100
# define COLOR	5000
# define UP		65362
# define DOWN	65364
# define RIGHT	65363
# define LEFT	65361
# define LEFT	65361
# define COLER1	109
# define COLER2	110
# define PLUS	59
# define MINUS	45
# define WHEEL1	4
# define WHEEL2	5
# define ESC	65307

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	char	*name;
	int		argc;
	void	*mlx;
	void	*win;
	int		loop;
	double	color;
	double	horizontal_move;
	double	vertical_move;
	double	zoom;
	double	julia_a;
	double	julia_b;
	t_data	img;
}				t_fractol;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_plot
{
	double	x;
	double	y;
}				t_plot;

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;

double		ft_atof(char *str);
void		draw_fractol(t_fractol *fractol);
int			key_hook(int key_code, t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex	*new_complex(double a, double b);
t_complex	*cal_add(t_complex **z1, t_complex **z2);
t_complex	*cal_multi(t_complex **z1, t_complex **z2);
double		ft_abs_complex(t_complex *z);
void		set_complex(t_complex *z, double a, double b);
void		validate(int argc, char **argv);
void		init_fractol(t_fractol **fractol, int argc, char **argv);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
