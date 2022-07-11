/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:10:32 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/24 18:27:05 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* 
int main()
{
	char	b[] = "1234567890", bu[] = "1234567890";
	char	*s = "", *st = "";
	size_t	n = 4;

	s = memset(b, '1', n);
	printf("%s\n", s);
	st = ft_memset(bu, '1', n);
	printf("%s\n", st);
}
 */