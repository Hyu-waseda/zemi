/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:30:23 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 18:02:09 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst == 0 && src == 0)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
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
	char	b6[] = "1234567890";
	char	b7[] = "1234567890";
	char	b8[] = "1234567890";
	char	src[] = "aiueokakikukeko";

	printf("%s\n", (char *)memcpy(b1, src, 3));
	printf("%s\n", (char *)ft_memcpy(b2, src, 3));
	printf("%s\n", (char *)memcpy(b3, b3 + 3, 6));
	printf("%s\n", (char *)ft_memcpy(b4, b4 + 3, 6));
	printf("%s\n", (char *)memcpy(b5 + 3, b5, 6));
	printf("%s\n", (char *)ft_memcpy(b6 + 3, b6, 6));
	
	//printf("%s\n", (char *)memmove(b7, src, 100));
	//printf("%s\n", (char *)memmove(NULL, src, 3));
	//printf("%s\n", (char *)memmove(b8, NULL, 3));
	//printf("%s\n", (char *)memmove(NULL, NULL, 3));
	//printf("%s\n", (char *)ft_memmove(NULL, NULL, 3));
}
 */