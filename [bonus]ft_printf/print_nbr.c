/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:42:17 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 20:38:21 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(long long n);

int	print_signed_int(int n)
{
	char		digit[11];
	long long	num;
	int			length;
	int			sign_cnt;

	num = n;
	sign_cnt = 0;
	ft_bzero(digit, 11);
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		sign_cnt = 1;
	}
	length = count_digit(num);
	while (length > 0)
	{
		digit[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	return (ft_putstr(digit) + sign_cnt);
}

int	print_unsigned_int(unsigned int n)
{
	char		digit[11];
	long long	num;
	int			length;
	int			sign_cnt;

	num = (long long)n;
	sign_cnt = 0;
	ft_bzero(digit, 11);
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		sign_cnt = 1;
	}
	length = count_digit(num);
	while (length > 0)
	{
		digit[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	return (ft_putstr(digit));
}

static int	count_digit(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt = 1;
	else if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}
