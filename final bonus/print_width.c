/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:02:26 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:33:34 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_space_or_zero(t_field *field, char *result, int prefix);
static void	print_str(t_field *field, char *result);
static void	print_prefix(t_field *field, char *result);
static void	print_res(t_field *field, char *result, int order);

void	print_width(t_field *field, char *result)
{
	char	str_len;
	char	prefix;

	prefix = w_prefix_len(field, result);
	str_len = ft_strlen(result + prefix_len(field)) - prefix;
	if (field -> width < str_len)
	{
		print_res(field, result, 4);
		return ;
	}
	if (field -> precision > -1)
		field -> flag_zero = 0;
	if (field -> flag_zero)
		print_res(field, result, 3);
	else
	{
		if (field -> flag_minus)
			print_res(field, result, 1);
		else
			print_res(field, result, 2);
	}
}

static void	print_res(t_field *field, char *result, int order)
{
	if (order == 1)
	{
		print_prefix(field, result);
		print_str(field, result);
		print_space_or_zero(field, result, w_prefix_len(field, result));
	}
	else if (order == 2)
	{
		print_space_or_zero(field, result, w_prefix_len(field, result));
		print_prefix(field, result);
		print_str(field, result);
	}
	else if (order == 3)
	{
		print_prefix(field, result);
		print_space_or_zero(field, result, w_prefix_len(field, result));
		print_str(field, result);
	}
	else if (order == 4)
	{
		print_prefix(field, result);
		print_str(field, result);
	}
	else
		return ;
}

static int	print_space_or_zero(t_field *field, char *result, int prefix)
{
	int		diff;
	int		i;
	char	c;
	int		str_len;

	str_len = ft_strlen(result);
	if (field -> specifier == 'c' && ft_strlen(result) == 0)
		str_len = 1;
	else if (ft_strchr("di", field -> specifier) && ft_strlen(result) == 0)
		str_len = 1;
	diff = field -> width - str_len - prefix + prefix_len(field);
	i = -1;
	c = ' ';
	if (field -> flag_zero && !(field -> flag_minus) && field -> precision < 0)
		c = '0';
	while (++i < diff)
		write(1, &c, 1);
	return (prefix);
}

static void	print_str(t_field *field, char *result)
{
	if (field -> specifier == 'c' && ft_strlen(result) == 0)
	{
		write(1, "\0", 1);
		return ;
	}
	ft_putstr(result + prefix_len(field));
}

static void	print_prefix(t_field *field, char *result)
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p')
		write(1, result, 2);
	else if ((sp == 'x' || sp == 'X') && field -> flag_sharp)
	{
		if (!is_x_zero(result))
			write(1, result, 2);
	}
	else if (sp == 'd' || sp == 'i')
	{
		if (result[0] == '-')
			write(1, result, 1);
		else if (result[0] == '+')
		{
			if (field -> flag_plus)
				write (1, result, 1);
			else if (field -> flag_blank)
				write(1, " ", 1);
		}
	}
}
