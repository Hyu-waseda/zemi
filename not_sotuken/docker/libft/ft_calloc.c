/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:33:22 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/05 18:16:48 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (count == 0 || size == 0)
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (s == 0)
			return (NULL);
		s[0] = '\0';
		return ((void *)s);
	}
	s = (char *)malloc(count * size);
	if (s == 0)
		return (NULL);
	ft_bzero(s, count * size);
	return ((void *)s);
}
/* 
int main()
{
	char *s1 = (char *)calloc(5, sizeof(char));
	char *s2 = (char *)ft_calloc(5, sizeof(char));
	printf("%d\n", memcmp(s1, s2, 5));

	int *s3 = (int *)calloc(100, sizeof(int));
	int *s4 = (int *)ft_calloc(100, sizeof(int));
	printf("%d\n", memcmp(s3, s4, 100));

	int *s5 = (int *)calloc(0, sizeof(int));
	int *s6 = (int *)ft_calloc(0, sizeof(int));
	printf("%d\n", memcmp(s5, s6, 8539));
	printf("s5 = %d, s6 = %d\n", s5[0], s6[0]);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*s;
	size_t			i;

	uc = (unsigned char)c;
	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = uc;
		i++;
	}
	return (b);
}
 */