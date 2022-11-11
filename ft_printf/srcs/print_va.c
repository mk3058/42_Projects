/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 20:38:20 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_va(va_list va, char specifier)
{
	if (specifier == 'c')
	{
		ft_putchar_fd(va_arg(va, int), 1);
		return (1);
	}
	else if (specifier == 'd' || specifier == 'i')
		return (print_signed_int(va_arg(va, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (specifier == 'p')
		return (addr_to_hex(va_arg(va, void *)));
	else if (specifier == 'u')
		return (print_unsigned_int(va_arg(va, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (integer_to_hex(va_arg(va, int), specifier));
	else if (specifier == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	else
		return (0);
}
