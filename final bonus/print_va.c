/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/15 13:24:37 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_mem_pre(t_field *field, va_list va);
static char	*allocate_mem(t_field *field, va_list va);
void		set_pointer(char *(*allocate_func[2])(t_field *field, va_list va));

int	print_va(va_list va, t_field *field)
{
	char		*(*allocate_func[2])(t_field *field, va_list va);
	char		*result;
	int			err;
	va_list		cpy;

	va_copy(cpy, va);
	set_pointer(allocate_func);
	result = allocate_func[(field -> precision) > -1](field, cpy);
	if (result == 0)
		return (-1);
	if (field -> precision > -1)
		err = precision_wrapper(result, field, va);
	else
		err = set_mem(result, field, va);
	if (err)
		return (-1);
	print_width(field, result);
	free(result);
	return (0); //길이 반환 필요
}

static char	*allocate_mem_pre(t_field *field, va_list va)
{
	char	*result;
	int		str_len;
	int		size;

	result = 0;
	str_len = find_len(va, field); //부호 자리, prefix 자리 포함
	if (field -> precision > str_len)
	{
		str_len = field -> precision;
		if (field -> specifier == 'x' || field -> specifier == 'X')
			str_len += 2;
		else if (field -> specifier == 'd' || field -> specifier == 'i')
			str_len += 1;
	}
	result = ft_calloc(str_len + 1, sizeof(char));
	if (result == 0)
			return (0);
	ft_memset(result, '0', str_len);
	va_end(va);
	return (result);
}

static char	*allocate_mem(t_field *field, va_list va)
{
	char	*result;
	int		str_len;

	result = 0;
	str_len = find_len(va, field); //부호 자리, prefix 자리가 이미 포함됨
	result = ft_calloc(str_len + 1, sizeof(char));
	va_end(va);
	return (result);
}

int	set_mem(char *result, t_field *field, va_list va)
{
	int	err;

	err = 0;
	if (field -> specifier == 'c')
		err = char_to_str(result, field, va_arg(va, int));
	else if (field -> specifier == 'd' || field -> specifier == 'i')
		err = nbr_to_str(result, field, va_arg(va, int));
	else if (field -> specifier == 's')
		err = str_to_str(result, field, va_arg(va, char *));
	else if (field -> specifier == 'p')
		err = addr_to_str(result, field, va_arg(va, void *));
	else if (field -> specifier == 'u')
		err = nbr_to_str(result, field, va_arg(va, unsigned int));
	else if (field -> specifier == 'x' || field -> specifier == 'X')
		err = integer_to_str(result, field, va_arg(va, unsigned int));
	else if (field -> specifier == '%')
		err = char_to_str(result, field, '%');
	if (err != 1)
		return (1);
	return (0);
}

void	set_pointer(char *(*allocate_func[2])(t_field *field, va_list va))
{
	allocate_func[0] = allocate_mem;
	allocate_func[1] = allocate_mem_pre;
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
