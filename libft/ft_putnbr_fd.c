/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:35:13 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:43:29 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	char			sign;
	long long int	num;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		num *= -1;
		sign = '-';
		write(fd, &sign, 1);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		num = num % 10;
	}
	c = '0' + num;
	write (fd, &c, 1);
}
