/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:55:39 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 10:54:02 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
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
		printf("%d %d\n", ft_isalpha(c), isalpha(c));
		c++;
	}
}
*/