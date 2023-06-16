/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:04:03 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/29 11:56:21 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/fractol.h"

static int	close_win(t_fractol *fractol);

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	validate(argc, argv);
	init_fractol(&fractol, argc, argv);
	draw_fractol(fractol);
	mlx_hook(fractol->win, 2, 1L << 0, key_hook, fractol);
	mlx_hook(fractol->win, 33, 1L << 17, close_win, fractol);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_loop(fractol->mlx);
	exit(0);
}

static int	close_win(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
}
