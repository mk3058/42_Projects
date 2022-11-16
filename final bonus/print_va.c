/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 13:18:52 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_return_size(char *result, t_field *field);

int	print_va(va_list va, t_field *field)
{
	char		*(*allocate_func[2])(t_field *field, va_list va);
	char		*result;
	int			err;
	va_list		cpy;
	int			size;

	set_pointer(allocate_func);
	va_copy(cpy, va);
	result = allocate_func[(field -> precision) > -1](field, cpy);
	if (result == 0)
		return (-1);
	if (field -> precision > -1)
		err = precision_wrapper(result, field, va);
	else
		err = set_mem(result, field, va);
	if (err)
		return (-1);
	size = get_return_size(result, field);
	print_width(field, result);
	free(result);
	return (size);
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

int	get_return_size(char *result, t_field *field)
{
	int	strlen;

	strlen = ft_strlen(result);
	if (field -> specifier == 'c' && strlen == 0)
		strlen = 1;
	strlen -= (prefix_len(field) - w_prefix_len(field, result));
	if (field -> width > strlen)
		return (field -> width);
	else
		return (strlen);
}
