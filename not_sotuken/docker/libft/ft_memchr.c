/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:29:51 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:32:19 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			s_len;
	size_t			i;

	str = (unsigned char *)s;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1 && i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/* 
int main()
{
	char s1[] = "1234567890asdfghjkl1234567890asdfghjkl";
	char s2[] = "1234567890asdfghjkl1234567890asdfghjkl";
	printf("%s\n", (char *)memchr(s1, 'a', 30));
	printf("%s\n", (char *)ft_memchr(s2, 'a', 30));
	char s3[] = "1234567890asdfghjkl1qwefghn12werty";
	char s4[] = "1234567890asdfghjkl1qwefghn12werty";
	printf("%s\n", (char *)memchr(s3, '1', 30));
	printf("%s\n", (char *)ft_memchr(s4, '1', 30));
	char s5[] = "1234567890asdfghjkl";
	char s6[] = "1234567890asdfghjkl";
	printf("%s\n", (char *)memchr(s5, 0, 30));
	printf("%s\n", (char *)ft_memchr(s6, 0, 30));
	char s7[] = "1234567890asdfghjkl";
	char s8[] = "1234567890asdfghjkl";
	printf("%s\n", (char *)memchr(s7, 'p', 30));
	printf("%s\n", (char *)ft_memchr(s8, 'p', 30));
	char s9[] = "1234567890asdfghjkl";
	char s10[] = "1234567890asdfghjkl";
	printf("%s\n", (char *)memchr(s9, 'j', 30));
	printf("%s\n", (char *)ft_memchr(s10, 'j', 30));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
 */