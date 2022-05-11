/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:43:49 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/04 16:54:22 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* 
int main()
{
	char	dst1[100] = "abcdef";
	char	dst2[100] = "abcdef";
	char	dst3[100] = "abcdef";
	char	dst4[100] = "abcdef";
	char	dst5[100] = "abcdef";
	char	dst6[100] = "abcdef";
	char	dst7[100] = "abcdef";
	char	dst8[100] = "abcdef";
	char	dst9[100] = "abcdef";
	char	dst10[100] = "abcdef";
	char	dst11[100] = "abcdef";
	char	src[] = "1234567890";


	printf("%zu, %s\n", strlcpy(dst1, src, 5), dst1);
	printf("%zu, %s\n", ft_strlcpy(dst2, src, 5), dst2);
	printf("%zu, %s\n", strlcpy(dst3, src, 100), dst3);
	printf("%zu, %s\n", ft_strlcpy(dst4, src, 100), dst4);
	printf("%zu, %s\n", strlcpy(dst5, src, 0), dst5);
	printf("%zu, %s\n", ft_strlcpy(dst6, src, 0), dst6);
	printf("%zu, %s\n", strlcpy(dst7, "", 5), dst7);
	printf("%zu, %s\n", ft_strlcpy(dst8, "", 5), dst8);
	printf("%zu\n", strlcpy(NULL, src, 0));
	printf("%zu\n", ft_strlcpy(NULL, src, 0));
	
	//printf("%zu\n", strlcpy(dst9, dst9 + 3, 6));
	//printf("%zu\n", strlcpy(dst9 + 3, dst9, 6));
	//printf("%zu, %s\n", strlcpy("", src, 5), dst9);
	//printf("%zu, %s\n", strlcpy("", "", 5), dst9);
	//printf("%zu\n", strlcpy(NULL, src, 3));
	//printf("%zu\n", strlcpy(dst9, NULL, 0));
	//printf("%zu\n", strlcpy(dst9, NULL, 3));
	//printf("%zu\n", strlcpy(NULL, NULL, 3));

	char	*str = "the cake is a lie !\0I'm hidden lol\r\n";
	char	buff1[0xF00];
	char	buff2[0xF00];
	
	memset(buff1, 'A', sizeof(buff1) - 1);
	memset(buff2, 'A', sizeof(buff2) - 1);
	buff1[sizeof(buff1) - 1] = 0;
	buff2[sizeof(buff1) - 1] = 0;

	//strlcpy(buff1, str, sizeof(buff1));
	//ft_strlcpy(buff2, str, sizeof(buff2));
			
	printf("%lu, %s\n", strlcpy(buff1, str, sizeof(buff1)), buff1);
	printf("%lu, %s\n", strlcpy(buff2, str, sizeof(buff2)), buff2);
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