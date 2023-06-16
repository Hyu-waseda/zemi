/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:48:45 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/04 16:51:35 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	i = 0;
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (dst_len + src_len);
}
/* 
int main()
{
 	char	dst1[100] = "1234567890";
	char	dst2[100] = "1234567890";
	char	dst3[100] = "1234567890";
	char	dst4[100] = "1234567890";
	char	dst5[100] = "1234567890";
	char	dst6[100] = "1234567890";
	char	dst7[100] = "1234567890";
	char	dst8[100] = "1234567890";
	char	dst9[100] = "1234567890";
	char	dst10[100] = "1234567890";
	char	src1[] = "aiue";
	char	src2[] = "aiue";
	char	src3[] = "aiue";
	char	src4[] = "aiue";
	char	src5[] = "aiue";
	char	src6[] = "aiue";
	char	src7[] = "aiue";
	char	src8[] = "aiue";
	char	src9[] = "aiue";
	char	src10[] = "aiue";
	
	printf("%zu, dst = %s\n", ft_strlcat(dst1, src1, 3), dst1);
	printf("%zu, dst = %s\n", strlcat(dst2, src2, 3), dst2);
	printf("%zu, dst = %s\n", ft_strlcat(dst3, src3, 12), dst3);
	printf("%zu, dst = %s\n", strlcat(dst4, src4, 12), dst4);
	printf("%zu, dst = %s\n", ft_strlcat(dst5, src5, 15), dst5);
	printf("%zu, dst = %s\n", strlcat(dst6, src6, 15), dst6);
	printf("%zu, dst = %s\n", ft_strlcat(dst7, src7, 0), dst7);
	printf("%zu, dst = %s\n", strlcat(dst8, src8, 0), dst8);
	 

	
	//printf("%zu, dst = %s\n", strlcat(NULL, src7, 3), dst7);
	//printf("%zu, dst = %s\n", ft_strlcat(NULL, src7, 3), dst7);
	//printf("%zu, dst = %s\n", strlcat(dst7, NULL, 3), dst7);
	//printf("%zu, dst = %s\n", ft_strlcat(dst7, NULL, 3), dst7);
	//printf("%zu, dst = %s\n", strlcat(NULL, NULL, 3), dst7);
	//printf("%zu, dst = %s\n", ft_strlcat(NULL, NULL, 3), dst7);
}

	size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
 */