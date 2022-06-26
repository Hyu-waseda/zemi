/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:32:34 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/01/25 17:58:05 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n);

static void	solve(long long int n, char *str, int digit, char sign);

char	*ft_itoa(int n)
{
	char			*str;
	long long int	num;
	int				digit;
	char			sign;

	digit = count_digit(n);
	num = (long long int)n;
	sign = '+';
	if (num < 0)
	{
		sign = '-';
		num *= -1;
	}
	if (sign == '-' || n == 0)
		str = (char *)malloc(sizeof(char) * (digit + 2));
	else
		str = (char *)malloc(sizeof(char) * (digit + 1));
	if (str == 0)
		return (NULL);
	solve(num, str, digit, sign);
	return (str);
}

static int	count_digit(int n)
{
	int	digit;

	digit = 0;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	solve(long long int num, char *str, int digit, char sign)
{
	if (sign == '-' || num == 0)
	{
		if (sign == '-')
			str[0] = '-';
		else
			str[0] = '0';
		digit++;
	}
	str[digit] = '\0';
	while (num != 0)
	{
		str[digit - 1] = '0' + (num % 10);
		num /= 10;
		digit--;
	}
	return ;
}
/* 
int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(12));
	printf("%s\n", ft_itoa(123));
	
}
 */