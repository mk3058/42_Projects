/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:14:32 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/12 09:10:43 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (s == 0)
		return (ft_putstr("(null)"));
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
