/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:35:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/15 00:10:56 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> ///////////////////
static char *convert_hex(size_t num, char *base, t_field *field);
static int  add_prefix(char *result, t_field *field);

int addr_to_str(char *result, t_field *field, void *input)
{
    char    *hex_str;

    hex_str = convert_hex((unsigned long long)input, "0123456789abcdef", field);
	if (hex_str == 0)
        return (-1);
    str_to_str(result, field, hex_str);
    free(hex_str);
	return (1);
}

int integer_to_str(char *result, t_field *field, unsigned int input)
{
	char	specifier;
    char    *hex_str;

	specifier = field -> specifier;
	if (specifier == 'x')
	{
		hex_str = convert_hex((unsigned int)input, "0123456789abcdef", field);
	    if (hex_str == 0)
            return (-1);
        str_to_str(result, field, hex_str);
	}
	else
	{
		hex_str = convert_hex((unsigned int)input, "0123456789ABCDEF", field);
	    if (hex_str == 0)
            return (-1);
        str_to_str(result, field, hex_str);
	}
    free(hex_str);
	return (1);
}

static char *convert_hex(size_t num, char *base, t_field *field)
{
	int	    mod;
    int     size;
    int     index;
    int     tmp;
    char    *result;
    char    specifier;

    size = ft_hexlen(num, field);
    result = ft_calloc(size + 1, sizeof(char));
    if (result == 0)
        return (0);
    tmp = add_prefix(result, field);    
    index = size - 1;
	while (index >= tmp)
    {
        mod = num % 16;
        num /= 16;
        result[index--] = *(base + mod);
    }
    return (result);
}

static int add_prefix(char *result, t_field *field)
{
    char    specifier;
    int     index;

    index = 0;
    specifier = field -> specifier;
    result[index++] = '0';
    if (specifier == 'X' || specifier == 'x')
        result[index++] = specifier;
    else if (specifier == 'p')
        result[index++] = 'x';
    return (index);
}