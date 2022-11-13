/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:21:44 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 22:03:28 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> ///////////

static void	print_sign(t_field *field, va_list va);
int			print_form(t_field *field, va_list va);

int	print_va(va_list va, t_field *field)
{
	char	specifier;
	int		tot_len;

	specifier = field -> specifier;
	print_sign(field, va);
	tot_len = print_form(field, va);
	if (specifier == 'c')
		ft_putchar(va_arg(va, int));
	else if (specifier == 'd' || specifier == 'i')
		print_signed_int(va_arg(va, int));
	else if (specifier == 's')
		ft_putstr_n(va_arg(va, char *), field -> precision);
	else if (specifier == 'p')
		addr_to_hex(va_arg(va, void *));
	else if (specifier == 'u')
		print_unsigned_int(va_arg(va, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		integer_to_hex(va_arg(va, int), field);
	else if (specifier == '%')
		return (ft_putchar('%'));
	else
		return (0);
	return (tot_len);
}

int	print_form(t_field *field, va_list va)
{
	int		size;
	char	specifier;
	int		i;
	int		diff;
	va_list	cp_va;

	i = 0;
	va_copy(cp_va, va);
	specifier = field -> specifier;
	size = find_len(&cp_va, field);
	if ((field -> width) > size && !field -> flag_minus)
	{
		diff = ((field -> width) - size);
		size = (field -> width);
		while (i < diff)
		{
			if (field -> flag_zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i++;
		}
	}
	va_end(cp_va);
	return (size);
}

static void	print_sign(t_field *field, va_list va)
{
	char	specifier;
	va_list	cp_va;

	va_copy(cp_va, va);
	specifier = field -> specifier;
	if ((specifier == 'd' || specifier == 'i') && va_arg(cp_va, int) > 0)
	{
		if (field -> flag_blank)
			write(1, " ", 1);
		else if (field -> flag_plus)
			write(1, "+", 1);
	}
}


	/*printf("flag_minus : %d\n", field -> flag_minus);
	printf("flag_plus : %d\n", field -> flag_plus);
	printf("flag_blank : %d\n", field -> flag_blank);
	printf("flag_sharp : %d\n", field -> flag_sharp);
	printf("flag_zero : %d\n", field -> flag_zero);
	printf("width : %d\n", field -> width);
	printf("precision : %d\n", field -> precision);
	printf("specifier : %c\n", field -> specifier);
	*/
