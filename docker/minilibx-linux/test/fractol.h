/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:34:19 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/02 01:33:18 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define HEIGHT 100
# define WIDTH 100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_fractol {
	char	*name;
	int		argc;
	void	*mlx;
	void	*win;
	int		roop;
	double	color;
	double	horizontal_move;
	double	vertical_move;
	double	zoom;
	double	julia_a;
	double	julia_b;
	t_data	img;
}				t_fractol;

typedef struct	s_complex {
	double	re;
	double	im;
}				t_complex;

typedef struct	s_plot {
	double	x;
	double	y;
}				t_plot;

typedef struct	s_coord {
	double	x;
	double	y;
}				t_coord;




#endif