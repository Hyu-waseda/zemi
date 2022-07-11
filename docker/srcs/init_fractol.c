/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:13:38 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/28 22:31:43 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractol(t_fractol **fractol, int argc, char **argv)
{
	(*fractol) = (t_fractol *)ft_xmalloc(sizeof(t_fractol) * 1);
	if (argc == 4)
	{
		(*fractol)->julia_a = ft_atof(argv[2]);
		(*fractol)->julia_b = ft_atof(argv[3]);
	}
	else
	{
		(*fractol)->julia_a = 0.32;
		(*fractol)->julia_b = 0.043;
	}
	(*fractol)->name = argv[1];
	(*fractol)->argc = argc;
	(*fractol)->mlx = mlx_init();
	(*fractol)->win = mlx_new_window(
			(*fractol)->mlx, WIDTH, HEIGHT, "(*fractol)");
	(*fractol)->loop = LOOP;
	(*fractol)->color = COLOR;
	(*fractol)->horizontal_move = 0;
	(*fractol)->vertical_move = 0;
	(*fractol)->zoom = 1;
	(*fractol)->img.img = mlx_new_image((*fractol)->mlx, WIDTH, HEIGHT);
	(*fractol)->img.addr = mlx_get_data_addr(
			(*fractol)->img.img, &((*fractol)->img.bits_per_pixel),
			&((*fractol)->img.line_length), &((*fractol)->img.endian));
}
