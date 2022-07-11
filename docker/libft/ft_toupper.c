/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:45:49 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 11:00:39 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
/* 
#include<stdio.h>
#include<ctype.h>

int main()
{
	for(int i = 0;i < 280;i++)
	{
		printf("%c %c\n", toupper(i), ft_toupper(i));
	}
}
 */