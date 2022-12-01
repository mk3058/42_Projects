/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:02:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/01 15:39:49 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static long long	my_atoi(const char *str, t_deque *a, t_deque *b);
static int			dup_check(t_deque *a);
static int			mark_cnt(t_deque *a);

void	get_arguments(int argc, char **argv, t_deque *a, t_deque *b)
{
	int	i;

	i = -1;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv = argv + 1;
	if (argc > 1)
	{
		while (argv[++i])
			push_tail(a, create_node(my_atoi(argv[i], a, b)));
		if (argc == 2)
			dealloc(argv, i);
	}
	if (argc < 2 || mark_cnt(a))
		exit_err(a, b);
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

static int	mark_cnt(t_deque *a)
{
	t_node	*head;
	t_node	*cur;
	int		cnt;
	int		dup;

	cur = a -> head;
	while (cur)
	{
		head = a -> head;
		cnt = 1;
		dup = 0;
		while (head)
		{
			if (head -> data < cur -> data)
				cnt++;
			if (head -> data == cur -> data)
				dup++;
			head = head -> next;
		}
		if (dup != 1)
			return (1);
		cur -> cnt = cnt;
		cur = cur -> next;
	}
	return (0);
}
