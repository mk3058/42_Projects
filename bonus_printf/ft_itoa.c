/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:56:12 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/14 20:22:05 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*my_itoa(long long n, t_field *field)
{
	char		*result;
	int			size;
	long long	num;
	int			i;

	i = 0;
	num = n;
	size = ft_numlen(n, field);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (result == 0)
		return (0);
	ft_memset(result, '0', size);
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
