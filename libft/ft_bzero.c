/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:03:47 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 17:57:08 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/* 
int	main(){
	char	s1[] = "aiueo";
	char	s2[] = "aiueo";
	char	s3[] = "aiueo";
	
	bzero(&s1[2], 3);
	printf("%s\n", s1);
	ft_bzero(&s2[2], 3);
	printf("%s\n", s2);
} 

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*s;
	size_t			i;

	uc = (unsigned char)c;
	s = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		s[i] = uc;
		i++;
	}
	return (b);
}
 */