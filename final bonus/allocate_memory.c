/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:35:16 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:46:45 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*allocate_mem_pre(t_field *field, va_list va);
static char	*allocate_mem(t_field *field, va_list va);

void	set_pointer(char *(*allocate_func[2])(t_field *field, va_list va))
{
	allocate_func[0] = allocate_mem;
	allocate_func[1] = allocate_mem_pre;
}

static char	*allocate_mem_pre(t_field *field, va_list va)
{
	char	*result;
	int		str_len;

	result = 0;
	str_len = find_len(va, field);
	if (field -> precision > str_len - prefix_len(field))
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
	str_len = find_len(va, field);
	result = ft_calloc(str_len + 1, sizeof(char));
	va_end(va);
	return (result);
}
