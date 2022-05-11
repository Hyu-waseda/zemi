/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:26:49 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/02 22:46:37 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_last_index(char const *s1, char const *set);

static int		check_trim(char const *s1, char const *set);

static char		*make_onesize_str(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	last;

	if (s1 == 0 || set == 0)
		return (NULL);
	if (set[0] == '\0' || s1[0] == '\0')
		return (ft_strdup((char *)s1));
	while (*s1 != '\0' && check_trim(s1, set))
		s1++;
	if (s1[0] == '\0')
		return (make_onesize_str());
	last = trim_last_index(s1, set);
	str = (char *)malloc(sizeof(char) * (last + 2));
	if (str == 0)
		return (NULL);
	i = 0;
	ft_memmove(str, s1, last + 1);
	str[last + 1] = '\0';
	return (str);
}

static int	check_trim(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == *s1)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_last_index(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	i = s1_len - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == '\0' || i == 0)
			break ;
		i--;
	}
	return (i);
}

static char	*make_onesize_str(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (str == 0)
		return (NULL);
	str[0] = '\0';
	return (str);
}
/* 
int main()
{
	char s1[] = "1234ABA22331122";
	char s2[] = "1234ABA";
	char s3[] = "ABA22331122";
	char s4[] = "ABA";
	char s5[] = "12342342342";
	char set[] = "1234";
	printf("1. %s\n", ft_strtrim(s1, set));
	printf("2. %s\n", ft_strtrim(s2, set));
	printf("3. %s\n", ft_strtrim(s3, set));
	printf("4. %s\n", ft_strtrim(s4, set));
	printf("5. %s\n", ft_strtrim(s5, set));
	printf("6. %s\n", ft_strtrim("", set));
	printf("7. %s\n", ft_strtrim(s1, ""));
	printf("8. %s\n", ft_strtrim("", ""));
	printf("9. %s\n", ft_strtrim(NULL, set));
	printf("10. %s\n", ft_strtrim(s1, NULL));
	printf("11. %s\n", ft_strtrim(NULL, NULL));
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if (dst == 0 && src == 0)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
 */