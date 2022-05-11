/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:57:55 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:33:10 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;
	char	*tmp;

	s_len = ft_strlen(s);
	i = 0;
	tmp = 0;
	while (i < s_len + 1)
	{
		if (s[i] == c)
			tmp = (char *)&s[i];
		i++;
	}
	return (tmp);
}

/* 
int main()
{
	char s1[] = "1234567890asdfghjkl1234567890asdfghjkl";
	printf("%s\n", strrchr(s1, 'a'));
	char s2[] = "1234567890asdfghjkl1234567890asdfghjkl";
	printf("%s\n", ft_strrchr(s2, 'a'));
	char s3[] = "1234567890asdfghjkl1qwefghn12werty";
	printf("%s\n", strrchr(s3, '1'));
	char s4[] = "1234567890asdfghjkl1qwefghn12werty";
	printf("%s\n", ft_strrchr(s4, '1'));
	char s5[] = "1234567890asdfghjkl";
	printf("%s\n", strrchr(s5, 0));
	char s6[] = "1234567890asdfghjkl";
	printf("%s\n", ft_strrchr(s6, 0));
	char s7[] = "1234567890asdfghjkl";
	printf("%s\n", strrchr(s7, 'p'));
	char s8[] = "1234567890asdfghjkl";
	printf("%s\n", ft_strrchr(s8, 'p'));
} 

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/