/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:53:33 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/16 18:28:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prefix_len(t_field *field)
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p' || (sp == 'x' || sp == 'X'))
		return (2);
	else if (sp == 'd' || sp == 'i')
		return (1);
	return (0);
}

int	w_prefix_len(t_field *field, char *result)
{
	char	sp;

	sp = field -> specifier;
	if (sp == 'p')
		return (2);
	else if ((sp == 'x' || sp == 'X') && field -> flag_sharp)
	{
		if (!is_x_zero(result))
			return (2);
	}
	else if (sp == 'd' || sp == 'i')
	{
		if (result[0] == '-')
			return (1);
		else if (result[0] == '+')
			if (field -> flag_plus || field -> flag_blank)
				return (1);
	}
	return (0);
}

int	is_x_zero(char *result)
{
	int	i;

	i = 2;
	while (result[i])
	{
		if (result[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
