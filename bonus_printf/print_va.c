/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/14 11:33:47 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> ///////////

static char	*allocate_mem(t_field *field, va_list va, int *valid_width);
static int	set_mem(char *result, t_field *field, va_list *va, int valid_width);

int	print_va(va_list *va, t_field *field)
{
	char	*result;
	int		valid_width;
	int		err;
	int		length;

	result = allocate_mem(field, *va, &valid_width);
	if (result == 0)
		return (-1);
	err = set_mem(result, field, va, valid_width);
	if (err)
		return (-1);
	length = ft_putstr(result);
	if (field -> specifier == 'c' && length == 0)
	{
		write(1, "\0", 1);
		length = 1;
	}
	free(result);
	return (length);
}

static int	set_mem(char *result, t_field *field, va_list *va, int valid)
{
	int	err;

	err = 0;
	if (field -> specifier == 'c')
		err = char_to_str(result, field, va_arg(*va, int), valid);
	else if (field -> specifier == 'd' || field -> specifier == 'i')
		err = nbr_to_str(result, field, va_arg(*va, int), valid);
	else if (field -> specifier == 's')
		err = str_to_str(result, field, va_arg(*va, char *), valid);
	else if (field -> specifier == 'p')
		err = addr_to_str(result, field, va_arg(*va, void *), valid);
	else if (field -> specifier == 'u')
		err = nbr_to_str(result, field, va_arg(*va, unsigned int), valid);
	else if (field -> specifier == 'x' || field -> specifier == 'X')
		err = integer_to_str(result, field, va_arg(*va, unsigned int), valid);
	else if (field -> specifier == '%')
		err = char_to_str(result, field, '%', valid);
	if (err != 1)
		return (1);
	return (0);
}

static char	*allocate_mem(t_field *field, va_list va, int *valid_width)
{
	int		size;
	char	*result;

	size = find_len(va, field);
	if ((field -> width) > size)
	{
		size = field -> width;
		*valid_width = 1;
	}
	else
		*valid_width = 0;
	result = ft_calloc(size + 1, sizeof(char));
	if (!(field -> flag_zero))
		ft_memset(result, ' ', size);
	else
		ft_memset(result, '0', size);
	return (result);
}
/*
	printf("flag_minus : %d\n", field -> flag_minus);
	printf("flag_plus : %d\n", field -> flag_plus);
	printf("flag_blank : %d\n", field -> flag_blank);
	printf("flag_sharp : %d\n", field -> flag_sharp);
	printf("flag_zero : %d\n", field -> flag_zero);
	printf("width : %d\n", field -> width);
	printf("precision : %d\n", field -> precision);
	printf("specifier : %c\n", field -> specifier);
*/
