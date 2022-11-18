/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:48 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 19:23:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	add_to_buff(char c, char *buff, int *index);
static int	print_buff(char *buff, int *buff_index);
static int	print(const char *format, va_list va, char *buff, t_field *field);

int	format_parser(const char *format, va_list va)
{
	int		return_value;
	char	buff[256];
	t_field	field;

	ft_bzero(buff, 256);
	return_value = print(format, va, buff, &field);
	if (return_value == -1)
		return (-1);
	return (return_value);
}

static int	print(const char *format, va_list va, char *buff, t_field *field)
{
	int	i;
	int	length;
	int	buff_index;
	int	return_value;

	i = -1;
	length = 0;
	buff_index = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			field_parser(format, &i, field);
			length += print_buff(buff, &buff_index);
			return_value = print_va(va, field);
			if (return_value == -1)
				return (-1);
			else
				length += return_value;
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
