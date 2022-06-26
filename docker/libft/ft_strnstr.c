/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:46:31 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 10:20:08 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_needle(const char *haystack, const char *needle,
				size_t len, size_t needle_len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	j = 0;
	needle_len = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	if (haystack[0] == 0 || len == 0)
		return (NULL);
	return (find_needle(haystack, needle, len, needle_len));
}

static char	*find_needle(const char *haystack, const char *needle,
	size_t len, size_t needle_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i + j < len)
	{
		j = 0;
		while (j < needle_len && i + j < len)
		{
			if (haystack[i + j] != needle[j])
			{
				j = 0;
				break ;
			}
			j++;
		}
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/* 
int main()
{
	char *haystack1 = strdup("abcdefghij1234567890"), *needle1 = strdup("ij");
	printf("haystack = %s, needle = %s\n", haystack1, needle1);
	for(int i = 0;i < 24;i++)
	{
		printf("i = %d\n", i);
		printf("%s\n", strnstr(haystack1, needle1, i));
		printf("%s\n", ft_strnstr(haystack1, needle1, i));
	}
	
	char haystack2[] = "1234567890", needle2[] = "456";
	printf("haystack = %s, needle = %s\n", haystack2, needle2);
	for(int i = 0;i < 24;i++)
	{
		printf("i = %d\n", i);
		printf("%s\n", strnstr(haystack2, needle2, i));
		printf("%s\n", ft_strnstr(haystack2, needle2, i));
	}
	
	char haystack3[] = "", needle3[] = "456";
	printf("haystack = %s, needle = %s\n", haystack3, needle3);
	for(int i = 0;i < 10;i++)
	{
		printf("i = %d\n", i);
		printf("%s\n", strnstr(haystack3, needle3, i));
		printf("%s\n", ft_strnstr(haystack3, needle3, i));
	}
	char haystack4[] = "1234567890", needle4[] = "";
	printf("haystack = %s, needle = %s\n", haystack4, needle4);
	for(int i = 0;i < 13;i++)
	{
		printf("i = %d\n", i);
		printf("%s\n", strnstr(haystack4, needle4, i));
		printf("%s\n", ft_strnstr(haystack4, needle4, i));
	}
	char haystack5[] = "", needle5[] = "";
	printf("haystack = %s, needle = %s\n", haystack5, needle5);
	for(int i = 0;i < 10;i++)
	{
		printf("i = %d\n", i);
		printf("%s\n", strnstr(haystack5, needle5, i));
		printf("%s\n", ft_strnstr(haystack5, needle5, i));
	}
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