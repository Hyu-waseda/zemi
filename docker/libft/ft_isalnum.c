/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:37:59 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 10:53:38 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
/*
#include<ctype.h>
#include<stdio.h>

int main(){
	char c = 0;
	for(int i = 0;i < 127;i++)
	{
		printf("%d %d\n", ft_isalnum(c), isalnum(c));
		c++;
	}
}
*/