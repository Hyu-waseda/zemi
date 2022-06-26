/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:40 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/03 15:38:46 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_complex	*new_complex(double a, double b)
{
	t_complex	*z;

	z = (t_complex *)ft_xmalloc(sizeof(t_complex) * 1);
	z->re = a;
	z->im = b;
	return (z);
}

double	ft_abs_complex(t_complex *z)
{
	return (sqrt(pow(z->re, 2) + pow(z->im, 2)));
}

void	set_complex(t_complex *z, double a, double b)
{
	z->re = a;
	z->im = b;
}
