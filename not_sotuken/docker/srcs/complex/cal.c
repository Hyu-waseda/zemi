/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:49:18 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/04/03 15:38:37 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static double	cal_multi_re(t_complex *z1, t_complex *z2);
static double	cal_multi_im(t_complex *z1, t_complex *z2);

t_complex	*cal_add(t_complex **z1, t_complex **z2)
{
	t_complex	*z;

	z = (t_complex *)ft_xmalloc(sizeof(t_complex) * 1);
	z->re = (*z1)->re + (*z2)->re;
	z->im = (*z1)->im + (*z2)->im;
	free(*z1);
	*z1 = NULL;
	free(*z2);
	*z2 = NULL;
	return (z);
}

t_complex	*cal_multi(t_complex **z1, t_complex **z2)
{
	t_complex	*z;

	z = (t_complex *)ft_xmalloc(sizeof(t_complex) * 1);
	z->re = cal_multi_re(*z1, *z2);
	z->im = cal_multi_im(*z1, *z2);
	free(*z1);
	*z1 = NULL;
	free(*z2);
	*z2 = NULL;
	return (z);
}

static double	cal_multi_re(t_complex *z1, t_complex *z2)
{
	return (z1->re * z2->re - z1->im * z2->im);
}

static double	cal_multi_im(t_complex *z1, t_complex *z2)
{
	return (z1->re * z2->im + z1->im * z2->re);
}
