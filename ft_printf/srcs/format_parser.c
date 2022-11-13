/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:48 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 13:47:40 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_buff(char *buff, int *buff_index);
static char	*get_field(const char *format, int *index);
static int	is_specifier(char c);

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
			field = get_field(format, &field);
			length += print_buff(buff, &buff_index);
			length += print_va(va, format[i], field);
			free(field.flag);
		}
		else
		{
			buff[buff_index++] = format[i];
			if (buff_index == 256)
				length += print_buff(buff, &buff_index);
		}
	}
	length += print_buff(buff, &buff_index);
	return (length);
}

static char	*field_parser(const char *format, int *index, t_field *field)
{
	int	length;

	
}

static int	is_specifier(char c)
{
	if (ft_strchr("cdispuxX%%", c))
		return (1);
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
