/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:53:05 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/28 23:10:14 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	move(int key_code, t_fractol *fractol);
static void	zoom_key(int key_code, t_fractol *fractol);
static void	color_change(int key_code, t_fractol *fractol);

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == ESC || key_code == 858305120)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	else if (key_code == RIGHT || key_code == LEFT
		|| key_code == UP || key_code == DOWN)
		move(key_code, fractol);
	else if (key_code == PLUS || key_code == MINUS)
		zoom_key(key_code, fractol);
	else if (key_code == COLER1 || key_code == COLER2)
		color_change(key_code, fractol);
	draw_fractol(fractol);
	return (0);
}

static void	move(int key_code, t_fractol *fractol)
{
	if (key_code == RIGHT)
		fractol->horizontal_move += 0.2 * fractol->zoom;
	else if (key_code == LEFT)
		fractol->horizontal_move -= 0.2 * fractol->zoom;
	else if (key_code == UP)
		fractol->vertical_move -= 0.2 * fractol->zoom;
	else if (key_code == DOWN)
		fractol->vertical_move += 0.2 * fractol->zoom;
}

static void	zoom_key(int key_code, t_fractol *fractol)
{
	if (key_code == PLUS)
	{
		fractol->zoom *= 0.9;
		fractol->loop += 4;
	}
	else if (key_code == MINUS)
	{
		fractol->zoom *= 1.1;
		fractol->loop -= 4;
	}
}

static void	color_change(int key_code, t_fractol *fractol)
{
	if (key_code == COLER1)
		fractol->color *= 2;
	else if (key_code == COLER2)
		fractol->color *= 0.50;
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == WHEEL1)
	{
		fractol->zoom *= 0.96;
		fractol->loop += 2;
	}
	else if (button == WHEEL2)
	{
		fractol->zoom *= 1.04;
		fractol->loop -= 2;
	}
	draw_fractol(fractol);
	return (0);
}
