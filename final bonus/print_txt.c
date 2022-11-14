/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:14:32 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/13 21:15:56 by minkyuki         ###   ########.fr       */
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

int	ft_putstr_n(char *s, int n)
{
	if (s == 0)
		return (ft_putstr("(null)"));
	if (n >= 0)
	{
		write(1, s, n);
		return (n);
	}
	else
		return (ft_putstr(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
