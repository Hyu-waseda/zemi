/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:29:48 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/08 11:30:32 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (1)
	{
		if (c1[i] != c2[i] || i == n - 1)
			break ;
		i++;
	}
	return (c1[i] - c2[i]);
}
/* 
int main()
{
	char s1[] = "abcdefg";
	for(int i = 0;i < 10;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", memcmp(s1, "abcdefg", i));
		printf("%d\n", ft_memcmp(s1, "abcdefg", i));
	}
	for(int i = 0;i < 10;i++)
	{
		//printf("i = %d\n", i);
		printf("%d\n", memcmp(s1, "abcefg", i));
		printf("%d\n", ft_memcmp(s1, "abcefg", i));
	}
	for(int i = 0;i < 10;i++)
	{
		//printf("i = %d\n", i);
		printf("%d\n", memcmp(s1, "", i));
		printf("%d\n", ft_memcmp(s1, "", i));
	}
	for(int i = 0;i < 10;i++)
	{
		//printf("i = %d\n", i);
		printf("%d\n", memcmp("", "abcefg", i));
		printf("%d\n", ft_memcmp("", "abcefg", i));
	}

} */
