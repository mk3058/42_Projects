/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:48 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 20:38:27 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_parser(const char *format, va_list va)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			length += print_va(va, format[++i]);
		else
		{
			ft_putchar_fd(format[i], 1);
			length++;
		}
		i++;
	}
	return (length);
}
