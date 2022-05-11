/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:53:47 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 10:54:33 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}
/*
#include<ctype.h>
#include<stdio.h>

int main(){
	char c = 0;
	for(int i = 0;i < 130;i++)
	{
		printf("%d %d\n", ft_isprint(c), isprint(c));
		c++;
	}
}
*/