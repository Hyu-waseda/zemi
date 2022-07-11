/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:41:39 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 10:54:14 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
#include<ctype.h>
#include<stdio.h>

int main(){
	char c = -5;
	for(int i = 0;i < 140;i++)
	{
		printf("%d %d\n", ft_isascii(c), isascii(c));
		c++;
	}
}
*/