/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:11:37 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/02/06 22:31:27 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
/* 
int main()
{
	char s1[] = "12345";
	char s2[] = "2147483647";
	char s3[] = "-2147483648";
	printf("s1 = %s, %d\n", s1, atoi(s1));
	printf("s1 = %s, %d\n", s1, ft_atoi(s1));
	printf("s2 = %s, %d\n", s2, atoi(s2));
	printf("s2 = %s, %d\n", s2, ft_atoi(s2));
	printf("s3 = %s, %d\n", s3, atoi(s3));
	printf("s3 = %s, %d\n", s3, ft_atoi(s3));
	char s4[] = "-1234";
	char s5[] = "--1234";
	char s6[] = "---1234";
	char s7[] = "----1234";
	char s8[] = "+1234";
	char s8_2[] = "++1234";
	char s9[] = "-+1234";
	char s9_2[] = "+-1234";
	printf("s4 = %s, %d\n", s4, atoi(s4));
	printf("s4 = %s, %d\n", s4, ft_atoi(s4));
	printf("s5 = %s, %d\n", s5, atoi(s5));
	printf("s5 = %s, %d\n", s5, ft_atoi(s5));
	printf("s6 = %s, %d\n", s6, atoi(s6));
	printf("s6 = %s, %d\n", s6, ft_atoi(s6));
	printf("s7 = %s, %d\n", s7, atoi(s7));
	printf("s7 = %s, %d\n", s7, ft_atoi(s7));
	printf("s8 = %s, %d\n", s8, atoi(s8));
	printf("s8 = %s, %d\n", s8, ft_atoi(s8));
	printf("s8_2 = %s, %d\n", s8_2, atoi(s8_2));
	printf("s8_2 = %s, %d\n", s8_2, ft_atoi(s8_2));
	printf("s9 = %s, %d\n", s9, atoi(s9));
	printf("s9 = %s, %d\n", s9, ft_atoi(s9));
	printf("s9_2 = %s, %d\n", s9_2, atoi(s9_2));
	printf("s9_2 = %s, %d\n", s9_2, ft_atoi(s9_2));
	char s10[] = "\n1234";
	char s11[] = "\t1234";
	char s12[] = " 1234";
	char s13[] = " 12 34";
	printf("s10 = %s, %d\n", s10, atoi(s10));
	printf("s10 = %s, %d\n", s10, ft_atoi(s10));
	printf("s11 = %s, %d\n", s11, atoi(s11));
	printf("s11 = %s, %d\n", s11, ft_atoi(s11));
	printf("s12 = %s, %d\n", s12, atoi(s12));
	printf("s12 = %s, %d\n", s12, ft_atoi(s12));
	printf("s13 = %s, %d\n", s13, atoi(s13));
	printf("s13 = %s, %d\n", s13, ft_atoi(s13));
	char s14[] = "+";
	char s15[] = "++";
	char s16[] = "-";
	char s17[] = "--";
	char s18[] = "";
	char s19[] = "21474836470";
	char s20[] = "-21474836480";
	printf("s14 = %s, %d\n", s14, atoi(s14));
	printf("s14 = %s, %d\n", s14, ft_atoi(s14));
	printf("s15 = %s, %d\n", s15, atoi(s15));
	printf("s15 = %s, %d\n", s15, ft_atoi(s15));
	printf("s16 = %s, %d\n", s16, atoi(s16));
	printf("s16 = %s, %d\n", s16, ft_atoi(s16));
	printf("s17 = %s, %d\n", s17, atoi(s17));
	printf("s17 = %s, %d\n", s17, ft_atoi(s17));
	printf("s18 = %s, %d\n", s18, atoi(s18));
	printf("s18 = %s, %d\n", s18, ft_atoi(s18));
	printf("s19 = %s, %d\n", s19, atoi(s19));
	printf("s19 = %s, %d\n", s19, ft_atoi(s19));
	printf("s20 = %s, %d\n", s20, atoi(s20));
	printf("s20 = %s, %d\n", s20, ft_atoi(s20));
}
 */