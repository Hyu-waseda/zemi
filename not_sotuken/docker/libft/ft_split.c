/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:44:45 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/06 22:17:04 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**get_str(char const *s, char c, size_t s_len);

static void	make_str(char const *s, char c, char **str, int is_all_c);

static char	*get_s1(char const *s, char c);

static void	free_str(char **str);

char	**ft_split(char const *s, char c)
{
	size_t	s_len;
	size_t	i;
	char	**str;

	if (s == 0)
		return (NULL);
	if (s[0] == '\0')
		return (get_str(s, c, 0));
	s_len = ft_strlen(s);
	str = get_str(s, c, s_len);
	if (str == 0)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	if (i == s_len)
		make_str(s, c, str, 1);
	else
		make_str(s, c, str, 0);
	if (str == 0 || str[0] == 0)
		return (NULL);
	return (str);
}

static char	**get_str(char const *s, char c, size_t s_len)
{
	char	**str;
	size_t	str_len;
	size_t	i;

	str_len = 0;
	i = 0;
	while (i < s_len)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			str_len++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	str = (char **)malloc(sizeof(char *) * (str_len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	while (i < str_len + 1)
	{
		str[i++] = 0;
	}
	str[str_len] = 0;
	return (str);
}

static void	make_str(char const *s, char c, char **str, int is_all_c)
{
	char	*s1;
	size_t	i;

	i = 0;
	while (*s != '\0' || is_all_c)
	{
		while (*s == c)
			s++;
		if ((*s != c && *s != '\0') || is_all_c)
		{
			is_all_c = 0;
			s1 = get_s1(s, c);
			str[i] = s1;
			if (s1 == 0)
			{
				free_str(str);
				return ;
			}
			i++;
		}
		while (*s != c && *s != '\0')
			s++;
	}
}

static char	*get_s1(char const *s, char c)
{
	char	*s1;
	char	*end_p;
	size_t	i;

	end_p = ft_strchr(s, c);
	if (end_p == 0)
		end_p = ft_strchr(s, '\0');
	i = 0;
	while (&s[i] != end_p)
		i++;
	s1 = (char *)malloc(sizeof(char) * i + 1);
	if (s1 == 0)
		return (NULL);
	s1[i] = '\0';
	i = 0;
	while (&s[i] != end_p)
	{
		s1[i] = s[i];
		i++;
	}
	return (s1);
}

static void	free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}

/* 
int main()
{
	char s1[] = "AAbbBBbbCC";
	char s2[] = "bbAAbbBBbbCC";
	char s3[] = "AAbbBBbbCCbb";
	char s4[] = "bbAAbBBbCCbb";
	char s5[] = "bAbBbCbDbEbFbG";
	char s6[] = "bbbbbbbbbbbbb";
	char **str;
	printf("s = %s\n", s1);
	str = ft_split(s1, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");
	
	printf("s = %s\n", s2);
	str = ft_split(s2, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");

	printf("s = %s\n", s3);
	str = ft_split(s3, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");

	printf("s = %s\n", s4);
	str = ft_split(s4, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");
	
	printf("s = %s\n", s5);
	str = ft_split(s5, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");

	printf("s = %s\n", s6);
	str = ft_split(s6, 'b');
	for(int i = 0;str[i] != 0;i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");

	system("leaks -q a.out");
	return 0;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	while (i != s_len + 1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
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