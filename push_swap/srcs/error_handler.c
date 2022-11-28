/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:02:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/28 19:22:45 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	is_equal(char *str1, char *str2);
static int	my_isdigit(char *c);

void	arguments_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		print_err();
	i = 0;
	while (++i < argc)
	{
		if (!my_isdigit(argv[i]))
			print_err();
		if (INT_MAX < ft_atoi(argv[i]) || ft_atoi(argv[i]) < INT_MIN)
			print_err();
		j = i;
		while (++j < argc)
		{
			if (is_equal(argv[i], argv[j]))
				print_err();
		}
	}
}

static int	my_isdigit(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
	}
	return (1);
}

static int	is_equal(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}

void	print_err(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}
