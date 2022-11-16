/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:52:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:37:19 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_specifier(char c);
static void	flag_parser(const char *format, int *index, t_field *field);
static void	initialize_struct(t_field *field);

void	field_parser(const char *format, int *index, t_field *field)
{
	*index = *index + 1;
	initialize_struct(field);
	flag_parser(format, index, field);
	if (ft_isdigit(format[*index]))
	{
		field -> width = ft_atoi(format + (*index));
		while (format[*index] != '.' && !is_specifier(format[*index]))
			*index = *index + 1;
	}
	if (format[*index] == '.')
	{
		*index = *index + 1;
		field -> precision = ft_atoi(format + (*index));
		while (!is_specifier(format[*index]))
			*index = *index + 1;
	}
	field -> specifier = format[*index];
}

static void	flag_parser(const char *format, int *index, t_field *field)
{
	char	cur_char;

	while (ft_strchr("-0# +", format[*index]))
	{
		cur_char = format[*index];
		if (cur_char == '-')
		{
			field -> flag_minus = 1;
			field -> flag_zero = 0;
		}
		else if (cur_char == '0' && !field -> flag_minus)
			field -> flag_zero = 1;
		else if (cur_char == '+')
		{
			field -> flag_plus = 1;
			field -> flag_blank = 0;
		}
		else if (cur_char == ' ' && !field -> flag_plus)
			field -> flag_blank = 1;
		else if (cur_char == '#')
			field -> flag_sharp = 1;
		*index = *index + 1;
	}
}

static int	is_specifier(char c)
{
	if (ft_strchr("cdispuxX%%", c))
		return (1);
	return (0);
}

static void	initialize_struct(t_field *field)
{
	field -> flag_minus = 0;
	field -> flag_plus = 0;
	field -> flag_blank = 0;
	field -> flag_sharp = 0;
	field -> flag_zero = 0;
	field -> width = 0;
	field -> precision = -1;
	field -> specifier = '\0';
}
