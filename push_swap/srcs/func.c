/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:22:24 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 17:24:12 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_deque *deque)
{
	int		min_cnt;
	int		min_ind;
	int		index;
	t_node	*node;

	min_cnt = deque -> head -> cnt;
	min_ind = 0;
	index = 1;
	node = deque -> head -> next;
	while (node)
	{
		if ((node -> cnt) < min_cnt)
		{
			min_cnt = node -> cnt;
			min_ind = index;
		}
		index++;
		node = node -> next;
	}
	return (min_ind);
}

int	find_max(t_deque *deque)
{
	int		max_cnt;
	int		max_ind;
	int		index;
	t_node	*node;

	max_cnt = deque -> head -> cnt;
	max_ind = 0;
	index = 1;
	node = deque -> head -> next;
	while (node)
	{
		if (node -> cnt > max_cnt)
		{
			max_cnt = node -> cnt;
			max_ind = index;
		}
		index++;
		node = node -> next;
	}
	return (max_ind);
}

int	is_asc(t_deque *deque)
{
	int		cnt;
	t_node	*node;

	node = deque -> head;
	cnt = -1;
	while (node)
	{
		if (cnt > node -> cnt)
			return (0);
		cnt = node -> cnt;
		node = node -> next;
	}
	return (1);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
