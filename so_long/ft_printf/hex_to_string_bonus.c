/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:35:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/16 18:53:26 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*convert_hex(size_t num, char *base, t_field *field);
static int	add_prefix(char *result, t_field *field);
static void	to_precision(char *result, char *hex_str, t_field *field);

int	addr_to_str(char *result, t_field *field, void *input)
{
	char	*hex_str;

	hex_str = convert_hex((unsigned long long)input, "0123456789abcdef", field);
	if (hex_str == 0)
		return (-1);
	str_to_str(result, field, hex_str);
	free(hex_str);
	return (1);
}

int	integer_to_str(char *result, t_field *field, unsigned int input)
{
	char	specifier;
	char	*hex_str;

	specifier = field -> specifier;
	if (specifier == 'x')
		hex_str = convert_hex((unsigned int)input, "0123456789abcdef", field);
	else
		hex_str = convert_hex((unsigned int)input, "0123456789ABCDEF", field);
	if (hex_str == 0)
		return (-1);
	to_precision(result, hex_str, field);
	free(hex_str);
	precision_input_zero(field, result, (long long)input);
	return (1);
}

static void	to_precision(char *result, char *hex_str, t_field *field)
{
	int	diff;

	diff = 0;
	result[0] = hex_str[0];
	result[1] = hex_str[1];
	if (field -> precision > -1)
		diff = ft_strlen(result) - ft_strlen(hex_str) + 2;
	else
		diff = 2;
	ft_memcpy(result + diff, hex_str + 2, ft_strlen(hex_str) - 2);
}

static char	*convert_hex(size_t num, char *base, t_field *field)
{
	int		mod;
	int		size;
	int		index;
	int		tmp;
	char	*result;

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

static int	add_prefix(char *result, t_field *field)
{
	char	specifier;
	int		index;

	index = 0;
	specifier = field -> specifier;
	result[index++] = '0';
	if (specifier == 'X' || specifier == 'x')
		result[index++] = specifier;
	else if (specifier == 'p')
		result[index++] = 'x';
	return (index);
}
