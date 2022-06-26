/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:31:32 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:55:49 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (s == 0 || f == 0)
		return (NULL);
	str = ft_strdup((char *)s);
	if (str == 0)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}
	return (str);
}
/* 
char f(unsigned int n, char c);

int main()
{
	
	char s[] = "000000000";
	printf("%s", ft_strmapi(s, f));
}

char f(unsigned int n, char c)
{
	return c + n;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * i + 1);
	if (p == NULL)
		return (p);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
 */