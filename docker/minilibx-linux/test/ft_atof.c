/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:36:32 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/03/31 14:38:23 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_integer_part(char **str);
static double	get_fractional_part(char **str);

double	ft_atof(char *str)
{
	double	x;
	double	sign;
	double	digit;
	size_t	i;

	i = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	x = get_integer_part(&str);
	x += get_fractional_part(&str);
	return (sign * x);
}

static double	get_integer_part(char **str)
{
	double	n;

	while (ft_isdigit(**str))
	{
		n = n * 10 + **str - '0';
		(*str)++;
	}
	return (n);
}

static double	get_fractional_part(char **str)
{
	double	n;
	double	digit;

	if (**str == '.')
		(*str)++;
	n = 0;
	digit = 0.1;
	while (ft_isdigit(**str))
	{
		n += (**str - '0') * digit;
		digit *= 0.1;
		(*str)++;
	}
	return (n);
}