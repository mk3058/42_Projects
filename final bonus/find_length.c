/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:57:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 12:52:57 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_len(va_list va, t_field *field)
{
	char	specifier;
	char	*str;

	specifier = field -> specifier;
	if (specifier == 'c' || specifier == '%')
		return (1);
	else if (specifier == 'd' || specifier == 'i')
		return (ft_numlen(va_arg(va, int), field));
	else if (specifier == 's')
		return (my_strlen(va_arg(va, char *), field -> precision));
	else if (specifier == 'p')
		return (ft_hexlen((size_t)va_arg(va, void *), field));
	else if (specifier == 'u')
		return (ft_numlen(va_arg(va, unsigned int), field) - 1);
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hexlen((size_t)va_arg(va, int), field));
	else
		return (0);
}

int	ft_hexlen(size_t input, t_field *field)
{
	int	length;

	length = 2;
	if (input == 0)
		length += 1;
	if (field -> specifier == 'x' || field -> specifier == 'X')
		input = (unsigned int)input;
	while (input > 0)
	{
		input /= 16;
		length++;
	}
	if (input == 0)
	return (length);
}

int	ft_numlen(long long n, t_field *field)
{
	int	cnt;

	cnt = 1;
	if (n == 0)
		cnt += 1;
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

int	my_strlen(char *str, int precision)
{
	if (!str)
		str = "(null)";
	if (precision > ft_strlen(str))
		return (ft_strlen(str));
	else
		return (precision);
}