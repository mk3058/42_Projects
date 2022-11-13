/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:02:49 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 20:28:38 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(size_t num, char *base, int *tot_len);

int	addr_to_hex(void *addr)
{
	int		tot_len;
	char	*base;

	tot_len = 3;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	print_hex((size_t)addr, base, &tot_len);
	return (tot_len);
}

int	integer_to_hex(unsigned int num, t_field *field)
{
	int		tot_len;
	char	specifier;

	tot_len = 1;
	specifier = field -> specifier;
	if (specifier == 'x')
	{
		if (field -> flag_sharp)
			write(1, "0x", 2);
		print_hex(num, "0123456789abcdef", &tot_len);
	}
	else
	{
		if (field -> flag_sharp)
			write(1, "0X", 2);
		print_hex(num, "0123456789ABCDEF", &tot_len);
	}
	return (tot_len);
}

static void	print_hex(size_t num, char *base, int *tot_len)
{
	int	mod;

	mod = (int)(num % 16);
	if (num > 0 && num >= 16)
	{
		*tot_len = *tot_len + 1;
		print_hex(num / 16, base, tot_len);
	}
	write(1, base + mod, 1);
}
