/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:57:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 17:34:31 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(size_t input, t_field *field);
static int	ft_numlen(long long n, t_field *field);

int	find_len(va_list *cp_va, t_field *field)
{
	char	specifier;

	specifier = field -> specifier;
	if (specifier == 'c' || specifier == '%')
		return (1);
	else if (specifier == 'd' || specifier == 'i')
		return (ft_numlen(va_arg(*cp_va, int), field));
	else if (specifier == 's')
		return (ft_strlen(va_arg(*cp_va, char *)));
	else if (specifier == 'p')
		return (ft_hexlen((size_t)va_arg(*cp_va, void *), field));
	else if (specifier == 'u')
		return (ft_numlen(va_arg(*cp_va, unsigned int), field));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hexlen((size_t)va_arg(*cp_va, int), field));
	else
		return (0);
}

static int	ft_hexlen(size_t input, t_field *field)
{
	int	length;

	length = 0;
	while (input > 0)
	{
		input /= 16;
		length++;
	}
	if (field -> flag_sharp)
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
