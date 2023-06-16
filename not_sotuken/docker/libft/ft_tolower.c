/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:53:17 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/11 11:00:46 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
/* 
#include<stdio.h>
#include<ctype.h>

int main()
{
	for(int i = 0;i < 280;i++)
	{
		printf("%c %c\n", tolower(i), ft_tolower(i));
	}
}
*/