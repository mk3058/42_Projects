/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:57:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/14 11:26:52 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long long n, t_field *field);

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
	{	
		str = va_arg(va, char *);
		if (!str)
			return (ft_strlen("(null)"));
		return (ft_strlen(str));
	}
	else if (specifier == 'p')
		return (ft_hexlen((size_t)va_arg(va, void *), field));
	else if (specifier == 'u')
		return (ft_numlen(va_arg(va, unsigned int), field));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hexlen((size_t)va_arg(va, int), field));
	else
		return (0);
}

int	ft_hexlen(size_t input, t_field *field)
{
	int	length;

	length = 0;
	if (input == 0)
		length += 1;
	if (field -> specifier == 'x' || field -> specifier == 'X')
		input = (unsigned int)input;
	while (input > 0)
	{
		input /= 16;
		length++;
	}
	if (field -> flag_sharp || field -> specifier == 'p')
		length += 2;
	return (length);
}

static int	ft_numlen(long long n, t_field *field)
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
	else if (field -> flag_blank || field -> flag_plus)
		cnt++;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}
