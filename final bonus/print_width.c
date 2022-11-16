/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:02:26 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 10:16:37 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_space_or_zero(t_field *field, char *result, int prefix);
static void	print_res(t_field *field, char *result);
static int	print_prefix(t_field *field, char *result);
static int	prefix_len(t_field *field, char *result);
static int	w_prefix_len(t_field *field, char *result);

void	print_width(t_field *field, char *result)
{
	char	str_len;
	int		printed_len;

	printed_len = 0;
	str_len = ft_strlen(result + prefix_len(field, result)) - w_prefix_len(field, result);
	if (field -> width < str_len)
	{
		print_prefix(field, result);
		print_res(field, result);
		return ;
	}
	if (field -> precision > -1)
	{
		field -> flag_zero = 0;
		if (field -> flag_minus)
		{
			printed_len = print_prefix(field, result);
			print_res(field, result);
			print_space_or_zero(field, result, printed_len);
		}
		else
		{
			printed_len = w_prefix_len(field, result);
			print_space_or_zero(field, result, printed_len);
			print_prefix(field, result);
			print_res(field, result);
		}
	}
	else
	{
		if (field -> flag_zero && field -> flag_minus)
			field -> flag_zero = 0;
		if (field -> flag_zero)
		{
			print_prefix(field, result);
			print_space_or_zero(field, result, w_prefix_len(field, result));
			print_res(field, result);
		}
		else
		{
			if (field -> flag_minus)
			{
				print_prefix(field, result);
				print_res(field, result);
				print_space_or_zero(field, result, w_prefix_len(field, result));
			}
			else
			{
				print_space_or_zero(field, result, w_prefix_len(field, result));
				print_prefix(field, result);
				print_res(field, result);
			}
		}
	}
}

static int	print_space_or_zero(t_field *field, char *result, int prefix) //출력될 prefix 길이 필요
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
	diff = field -> width - str_len - prefix + prefix_len(field, result);
	i = -1;
	c = ' ';
	if (field -> flag_zero && !(field -> flag_minus) && field -> precision < 0)
		c = '0';
	while (++i < diff)
		write(1, &c, 1);
	return (prefix);
}

static void	print_res(t_field *field, char *result) //prefix 제외한 결과만 출력 result 그대로 줘야함
{
	if (field -> specifier == 'c' && ft_strlen(result) == 0)
	{
		write(1, "\0", 1);
		return ;
	}	
	ft_putstr(result + prefix_len(field, result));
}

static int	print_prefix(t_field *field, char *result) //출력한 prefix 길이 반환
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p' || ((sp == 'x' || sp == 'X') && field -> flag_sharp))
	{
		write(1, result, 2);
		return (2);
	}
	else if (sp == 'd' || sp == 'i')
	{
		if (result[0] == '-')
		{
			write(1, result, 1);
			return (1);
		}
		else if (result[0] == '+')
		{
			if (field -> flag_plus)
				write (1, result, 1);
			else if (field -> flag_blank)
				write(1, " ", 1);
			if (field -> flag_plus || field -> flag_blank)
				return (1);
		}
	}
	return (0);
}

static int	prefix_len(t_field *field, char *result)
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p' || (sp == 'x' || sp == 'X'))
		return (2);
	else if (sp == 'd' || sp == 'i')
		return (1);
	return (0);
}

static int	w_prefix_len(t_field *field, char *result)
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p' || ((sp == 'x' || sp == 'X') && field -> flag_sharp))
		return (2);
	else if (sp == 'd' || sp == 'i')
	{
		if (result[0] == '-')
			return (1);
		else if (result[0] == '+')
			if (field -> flag_plus || field -> flag_blank)
				return (1);
	}
	return (0);
}
