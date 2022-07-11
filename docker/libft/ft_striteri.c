/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:37:42 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/31 16:38:05 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (s == 0 || f == 0)
		return ;
	str = (char *)s;
	if (str == 0)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		(*f)(i, &str[i]);
		i++;
	}
	return ;
}
/* 
void func(unsigned int n, char *c);

int main()
{
	void (*f)(unsigned int, char *);
	f = func;
	
	char s[] = "000000000";
	ft_striteri(s, f);
	printf("%s", s);
}

void func(unsigned int n, char *c)
{
	(*c)++;
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