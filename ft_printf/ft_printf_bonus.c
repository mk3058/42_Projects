/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:00:25 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:45:59 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list	va;

	va_start(va, format);
	length = format_parser(format, va);
	va_end(va);
	if (length == -1)
		return (-1);
	return (length);
}
