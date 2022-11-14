/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:36:37 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/15 00:23:16 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int precision_wrapper(char *result, t_field *field, va_list *va)
{
    int	err;

	err = 0;
	if (field -> specifier == 'c')
		err = char_to_str(result, field, va_arg(*va, int));
	else if (field -> specifier == 'd' || field -> specifier == 'i')
		err = nbr_to_str(result, field, va_arg(*va, int));
	else if (field -> specifier == 's')
		err = str_to_str(result, field, va_arg(*va, char *));
	else if (field -> specifier == 'u')
		err = nbr_to_str(result, field, va_arg(*va, unsigned int));
	else if (field -> specifier == 'x' || field -> specifier == 'X')
		err = integer_to_str(result, field, va_arg(*va, unsigned int));
	else
		set_mem(result, field, va);
	if (err != 1)
		return (1);
	return (0);
}