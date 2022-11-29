/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:02:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/29 18:46:08 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static long long	my_atoi(const char *str, t_deque *a, t_deque *b);
static int			dup_check(t_deque *a);

void	get_arguments(int argc, char **argv, t_deque *a, t_deque *b)
{
	int			i;
	long long	num;
	char		**res;

	i = 0;
	if (argc > 2)
	{
		while (++i < argc)
			push_tail(a, create_node(my_atoi(argv[i], a, b)));
	}
	else if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		while (res[i])
		{
			push_tail(a, create_node(my_atoi(res[i], a, b)));
			i++;
		}
		dealloc(res, i);
	}
	else
		exit_err(a, b);
	if (dup_check(a))
		exit_err(a, b);
}

static int	dup_check(t_deque *a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = a -> head;
	while (tmp1)
	{
		tmp2 = tmp1 -> next;
		while (tmp2)
		{
			if ((tmp1 -> data) == (tmp2 -> data))
				return (1);
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1 -> next;
	}
	return (0);
}

static long long	my_atoi(const char *str, t_deque *a, t_deque *b)
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
