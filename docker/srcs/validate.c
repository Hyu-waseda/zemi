/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:08:22 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/04 11:39:22 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	print_param(void);
static int	is_valid_param(char *x_str, char *y_str);
static int	is_fraction(const char *str);

void	validate(int argc, char **argv)
{
	if (argc == 1)
		print_param();
	else if ((ft_strncmp(argv[1], "Mandelbrot", 11) != 0)
		&& (ft_strncmp(argv[1], "Julia", 6) != 0)
		&& (ft_strncmp(argv[1], "Burningship", 13) != 0))
		print_param();
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc != 2)
		print_param();
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		if (argc != 2 && argc != 4)
			print_param();
		else if (argc == 4)
		{
			if (!is_valid_param(argv[2], argv[3]))
				print_param();
		}
	}
	else if (ft_strncmp(argv[1], "Burningship", 13) == 0 && argc != 2)
		print_param();
}

static void	print_param(void)
{
	printf("parameter error\n");
	printf("---------------\n");
	printf("Mandelbrot\n");
	printf("Julia\n");
	printf("Julia <x> <y>\n");
	printf("Burningship\n");
	exit (1);
}

static int	is_valid_param(char *x_str, char *y_str)
{
	double	x;

	if (!is_fraction(x_str) || !is_fraction(y_str)
		|| ft_strlen(x_str) > 16 || ft_strlen(y_str) > 16)
		return (0);
	x = ft_atof(x_str);
	return (1);
}

static int	is_fraction(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || str[i] == '.')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '.')
		i++;
	if (str[i] == '\0')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (i == ft_strlen(str) && str[i] == '\0')
		return (1);
	return (0);
}
