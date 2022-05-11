/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:01:44 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/05 18:17:28 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		s_len;
	size_t		i;

	if (s == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	s_len = ft_strlen(s);
	if (len == 0 || s_len <= start)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (i < len && start + i < s_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 
int main()
{
	char s1[] = "0123456789";
	char *s2, *s3, *s4, *s5;
	
	s2 = ft_substr(s1, 3, 3);
	printf("%s\n", s2);
	s3 = ft_substr(s1, 3, 10);
	printf("%s\n", s3);
	s4 = ft_substr(s1, 3, 0);
	printf("%s\n", s4);
	s5 = ft_substr("", 3, 3);
	printf("%s\n", s5);
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