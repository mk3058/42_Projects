/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:02:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/29 13:15:17 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	arguments_check(int argc, char **argv, t_deque *a, t_deque *b)
{
	int			i;
	long long	num;

	i = 0;
	if (argc > 2)
	{
		while (++i < argc)
		{
			
		}
	}
	else if (argc == 2)
	{

	}
	else
		print_err();
}

static long long	ft_atoi(const char *str, t_deque *a, t_deque *b)
{
	int			sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign *= -(str[i] == '-');
		i++;
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			exit_err(a, b);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (INT_MIN > result * sign || INT_MAX < result * sign)
		exit_err(a, b);
	return (result * sign);
}

void	exit_err(t_deque *a, t_deque *b)
{
	ft_putstr_fd("Error\n", 1);
	if (a && b)
	{
		free_deque(a);
		free_deque(b);
	}
	exit(EXIT_FAILURE);
}
