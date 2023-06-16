/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:22:45 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 18:03:17 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/* 

int main()
{
	char	b1[] = "1234567890";
	char	b2[] = "1234567890";
	char	b3[] = "1234567890";
	char	b4[] = "1234567890";
	char	b5[] = "1234567890";
	char	src[] = "aiueokakikukeko";

	printf("%s\n", (char *)memmove(b1, src, 3));
	printf("%s\n", (char *)ft_memmove(b2, src, 3));
	
	//printf("%s\n", (char *)memmove(b3, src, 100));
	//printf("%s\n", (char *)memmove(NULL, src, 3));
	//printf("%s\n", (char *)memmove(b4, NULL, 3));
	//printf("%s\n", (char *)memmove(NULL, NULL, 3));
	//printf("%s\n", (char *)ft_memmove(NULL, NULL, 3));
}
 */