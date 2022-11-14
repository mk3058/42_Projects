/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/15 01:17:32 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_mem_pre(t_field *field, va_list va);
static char	*allocate_mem(t_field *field, va_list va);

int	print_va(va_list *va, t_field *field)
{
	char	*result;
	int		valid_width;
	int		err;
	int		length;

	if (field -> precision > -1)
	{
		result = allocate_mem_pre(field, *va);
		if (result == 0)
			return (-1);
		err = precision_wrapper(result, field, va);
	}
	else
	{
		result = allocate_mem(field, *va);
		if (result == 0)
			return (-1);
		err = set_mem(result, field, va);
	}
	if (err)
		return (-1);
	/*length = ft_putstr(result);
	if (field -> specifier == 'c' && length == 0)
	{
		write(1, "\0", 1);
		length = 1;
	}*/
	printf("===res : %s===\n", result);
	free(result);
	return (length);
}

static char	*allocate_mem_pre(t_field *field, va_list va)
{
	char	*result;
	int		str_len;
	int		size;

	result = 0;
	str_len = find_len(va, field); //부호 자리, prefix 자리가 이미 포함됨
	if (field -> precision > str_len)
	{
		if (field -> specifier ==  ///////precision 대입할때도 부호, prefix 자리 만들어야함
		result = ft_calloc(field -> precision + 1, sizeof(char));
		if (result == 0)
			return (0);
		ft_memset(result, '0', field -> precision);
	}
	else
	{
		result = ft_calloc(str_len + 1, sizeof(char));
		if (result == 0)
			return (0);
		ft_memset(result, '0', str_len);
	}
	return (result);
}

static char	*allocate_mem(t_field *field, va_list va)
{
	char	*result;
	int		str_len;

	result = 0;
	str_len = find_len(va, field); //부호 자리, prefix 자리가 이미 포함됨
	result = ft_calloc(str_len + 1, sizeof(char));
	return (result);
}

int	set_mem(char *result, t_field *field, va_list *va)
{
	int	err;

	err = 0;
	if (field -> specifier == 'c')
		err = char_to_str(result, field, va_arg(*va, int));
	else if (field -> specifier == 'd' || field -> specifier == 'i')
		err = nbr_to_str(result, field, va_arg(*va, int));
	else if (field -> specifier == 's')
		err = str_to_str(result, field, va_arg(*va, char *));
	else if (field -> specifier == 'p')
		err = addr_to_str(result, field, va_arg(*va, void *));
	else if (field -> specifier == 'u')
		err = nbr_to_str(result, field, va_arg(*va, unsigned int));
	else if (field -> specifier == 'x' || field -> specifier == 'X')
		err = integer_to_str(result, field, va_arg(*va, unsigned int));
	else if (field -> specifier == '%')
		err = char_to_str(result, field, '%');
	if (err != 1)
		return (1);
	return (0);
}

	/*size = find_len(va, field);
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
	return (result); */
	
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
