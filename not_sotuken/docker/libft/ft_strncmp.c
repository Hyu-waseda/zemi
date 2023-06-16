/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:09:10 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 10:30:42 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* 
int main()
{
	
	char s1[] = "abcdefg";
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "abcefg", i));
		printf("%d\n", ft_strncmp(s1, "abcefg",i));
	}
	
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "abcefg", i));
		printf("%d\n", ft_strncmp(s1, "abcefg", i));
	}
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, "", i));
		printf("%d\n", ft_strncmp(s1, "", i));
	}
	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp("", "abcefg", i));
		printf("%d\n", ft_strncmp("", "abcefg", i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1, s1 + 2, i));
		printf("%d\n", ft_strncmp(s1, s1 + 2, i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp(s1 + 2, s1, i));
		printf("%d\n", ft_strncmp(s1 + 2, s1, i));
	}

	for(int i = 0;i < 9;i++)
	{
		printf("i = %d\n", i);
		printf("%d\n", strncmp("012345", "012", i));
		printf("%d\n", ft_strncmp("012345", "012", i));
	}
	
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