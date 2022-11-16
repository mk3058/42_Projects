/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:54 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:25 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_input_zero(t_field *field, char *result, long long input)
{
	char	specifier;

	specifier = field -> specifier;
	if (field -> precision == 0 && input == 0)
	{
		if (ft_strchr("Xxdiu", specifier) != 0)
			result[prefix_len(field)] = 0;
	}
}
