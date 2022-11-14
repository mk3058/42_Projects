/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:48 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 21:21:14 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_to_buff(char c, char *buff, int *index);
static int	print_buff(char *buff, int *buff_index);

int	format_parser(const char *format, va_list va)
{
	int		i;
	int		length;
	int		buff_index;
	char	buff[256];
	t_field	field;

	i = -1;
	length = 0;
	buff_index = 0;
	ft_bzero(buff, 256);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			field_parser(format, &i, &field);
			length += print_buff(buff, &buff_index);
			length += print_va(&va, &field);
		}
		else
			length += add_to_buff(format[i], buff, &buff_index);
	}
	length += print_buff(buff, &buff_index);
	return (length);
}

static int	add_to_buff(char c, char *buff, int *index)
{
	buff[*index] = c;
	*index = *index + 1;
	if (*index == 256)
		return (print_buff(buff, index));
	return (0);
}

static int	print_buff(char *buff, int *buff_index)
{
	int	length;

	length = 0;
	length = ft_putstr(buff);
	ft_bzero(buff, 256);
	*buff_index = 0;
	return (length);
}
