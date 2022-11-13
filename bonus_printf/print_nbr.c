/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:42:17 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 21:21:48 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(long long n);

int	print_signed_int(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = my_itoa(n);
	return (ft_putstr(str) + len);
}

int	print_unsigned_int(unsigned int n)
{
	char	*str;
	int		len;

	len = 0;
	str = my_itoa((long long)n);
	return (ft_putstr(str) + len);
}

int	ft_numlen(long long n)
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
