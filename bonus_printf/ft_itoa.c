/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:56:12 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 20:14:55 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(long long n);

char	*my_itoa(long long n)
{
	char		*result;
	int			size;
	long long	num;
	int			i;

	i = 0;
	num = n;
	size = count_digit(num);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (result == 0)
		return (0);
	if (num < 0)
	{
		result[0] = '-';
		i = 1;
		num *= -1;
	}
	while (size > i)
	{
		result[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
	return (result);
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
