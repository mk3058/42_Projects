/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:56 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 17:13:16 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_deque *a, t_deque *b);
static void	sort_three(t_deque *a, t_deque *b);
static void	sort_four(t_deque *a, t_deque *b);
static void	sort_five(t_deque *a, t_deque *b);

void	manual_sort(t_deque *a, t_deque *b)
{
	int	deq_size;

	deq_size = deque_size(a);
	if (deq_size == 2)
		sort_two(a, b);
	else if (deq_size == 3)
		sort_three(a, b);
	else if (deq_size == 4)
		sort_four(a, b);
	else if (deq_size == 5)
		sort_five(a, b);
}

static void	sort_two(t_deque *a, t_deque *b)
{
	if ((a -> head -> cnt) > (a -> head -> next -> cnt))
		sa(a, b);
}

static void	sort_three(t_deque *a, t_deque *b)
{
	if (is_asc(a))
		return ;
	if (find_min(a) == 0)
	{
		ra(a, b);
		sa(a, b);
		rra(a, b);
	}
	else if (find_min(a) == 1)
	{
		if (a -> head -> cnt > a -> head -> next -> next -> cnt)
			ra(a, b);
		else
			sa(a, b);
	}
	else
	{
		if (a -> head -> cnt < a -> head -> next -> cnt)
			rra(a, b);
		else
		{
			sa(a, b);
			rra(a, b);
		}
	}
}

static void	sort_four(t_deque *a, t_deque *b)
{
	int	min_ind;

	if (is_asc(a))
		return ;
	min_ind = find_min(a);
	if (min_ind <= (int)((double)deque_size(a) / 2 + 0.5))
		while (min_ind-- > 0)
			ra(a, b);
	else
		while (min_ind++ < deque_size(a))
			rra(a, b);
	pb(a, b);
	sort_three(a, b);
	pa(a, b);
}

static void	sort_five(t_deque *a, t_deque *b)
{
	int	min_ind;

	min_ind = find_min(a);
	if (min_ind <= (int)((double)deque_size(a) / 2 + 0.5))
		while (min_ind-- > 0)
			ra(a, b);
	else
		while (min_ind++ < deque_size(a))
			rra(a, b);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
