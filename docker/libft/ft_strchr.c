/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:02:51 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:32:41 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len + 1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/* 
int main()
{
	char s1[] = "1234567890asdfghjkl";
	printf("%s\n", strchr(s1, 'a'));
	char s2[] = "1234567890asdfghjkl";
	printf("%s\n", ft_strchr(s2, 'a'));
	char s3[] = "1234567890asdfghjkl";
	printf("%s\n", strchr(s3, '1'));
	char s4[] = "1234567890asdfghjkl";
	printf("%s\n", ft_strchr(s4, '1'));
	char s5[] = "1234567890asdfghjkl";
	printf("%s\n", strchr(s5, 0));
	char s6[] = "1234567890asdfghjkl";
	printf("%s\n", ft_strchr(s6, 0));
	char s7[] = "";
	printf("%s\n", strchr(s7, 1));
	char s8[] = "";
	printf("%s\n", ft_strchr(s8, 1));
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