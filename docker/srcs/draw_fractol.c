/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:55:07 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/28 22:32:36 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	do_draw(t_fractol *fractol, t_plot *plot, t_coord *coord);
static void	draw_mandelbrot(t_coord *coord, t_plot *plot, t_fractol *fractol);
static void	draw_julia(t_coord *coord, t_plot *plot, t_fractol *fractol);
static void	draw_ship(t_coord *coord, t_plot *plot, t_fractol *fractol);

void	draw_fractol(t_fractol *fractol)
{
	t_plot	*plot;
	t_coord	*coord;

	plot = (t_plot *)ft_xmalloc(sizeof(t_plot) * 1);
	coord = (t_coord *)ft_xmalloc(sizeof(t_coord) * 1);
	plot->x = 0;
	while (plot->x < HEIGHT)
	{
		coord->x = (plot->x * 4 / HEIGHT - 4 / 2) * fractol->zoom
			+ fractol->horizontal_move;
		plot->y = 0;
		while (plot->y < WIDTH)
		{
			coord->y = (plot->y * 4 / WIDTH - 4 / 2) * fractol->zoom
				+ fractol->vertical_move;
			do_draw(fractol, plot, coord);
			plot->y++;
		}
		(plot->x)++;
	}
	free(plot);
	free(coord);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

static void	do_draw(t_fractol *fractol, t_plot *plot, t_coord *coord)
{
	if (ft_strncmp(fractol->name, "Mandelbrot", 11) == 0)
		draw_mandelbrot(coord, plot, fractol);
	else if (ft_strncmp(fractol->name, "Julia", 6) == 0)
		draw_julia(coord, plot, fractol);
	else if (ft_strncmp(fractol->name, "Burningship", 11) == 0)
		draw_ship(coord, plot, fractol);
}

static void	draw_mandelbrot(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(0, 0);
	k = 1;
	while (k < fmax(fractol->loop, 50))
	{
		z = cal_multi(&z, &z);
		c = new_complex(coord->x, coord->y);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	free(z);
	if (k == fractol->loop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}

static void	draw_julia(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(coord->x, coord->y);
	k = 1;
	while (k < fmax(fractol->loop, 50))
	{
		z = cal_multi(&z, &z);
		c = new_complex(fractol->julia_a, fractol->julia_b);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	free(z);
	if (k == fractol->loop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}

static void	draw_ship(t_coord *coord, t_plot *plot, t_fractol *fractol)
{
	t_complex	*z;
	t_complex	*c;
	double		k;

	z = new_complex(coord->x, coord->y);
	k = 1;
	while (k < fmax(fractol->loop, 50))
	{
		set_complex(z, fabs(z->re), fabs(z->im));
		z = cal_multi(&z, &z);
		c = new_complex(coord->x, coord->y);
		z = cal_add(&z, &c);
		if (ft_abs_complex(z) > 2)
		{
			my_mlx_pixel_put(
				&(fractol->img), plot->x, plot->y, k * fractol->color);
			break ;
		}
		k++;
	}
	free(z);
	if (k == fractol->loop)
		my_mlx_pixel_put(&(fractol->img), plot->x, plot->y, 0x00000000);
}
