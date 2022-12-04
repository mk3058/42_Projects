/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:37:37 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/04 14:33:57 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_first(t_deque *a, t_deque *b, int *target);
static void	rrr_first(t_deque *a, t_deque *b, int *target);
static void	other(t_deque *a, t_deque *b, int *target);

void	sort(t_deque *a, t_deque *b, int *target)
{
	int	a_size;
	int	b_size;

	a_size = deque_size(a);
	b_size = deque_size(b);
	if (target[0] <= (a_size / 2) && target[1] <= (b_size / 2))
		rr_first(a, b, target);
	else if (target[0] > (a_size / 2) && target[1] > (b_size / 2))
		rrr_first(a, b, target);
	else
		other(a, b, target);
}

static void	rr_first(t_deque *a, t_deque *b, int *target)
{
	while (target[0] >= 0 && target[1] >= 0)
	{
		rr(a, b);
		target[0]--;
		target[1]--;
	}
	while (target[0] >= 0)
	{
		ra(a, b);
		target[0]--;
	}
	while (target[1] >= 0)
	{
		rb(a, b);
		target[1]--;
	}
	pb(a, b);
}

static void	rrr_first(t_deque *a, t_deque *b, int *target)
{
	int	a_size;
	int	b_size;

	a_size = deque_size(a);
	b_size = deque_size(b);
	while (target[0] < a_size && target[1] < b_size)
	{
		rrr(a, b);
		target[0]++;
		target[1]++;
	}
	while (target[0] < a_size)
	{
		rra(a, b);
		target[0]++;
	}
	while (target[1] < b_size)
	{
		rrb(a, b);
		target[1]++;
	}
	pb(a, b);
}

static void	other(t_deque *a, t_deque *b, int *target)
{
	int	a_size;
	int	b_size;

	a_size = deque_size(a);
	b_size = deque_size(b);
	if (target[0] <= (a_size / 2))
	{
		while (target[0]-- >= 0)
			ra(a, b);
	}
	else
	{
		while (target[0]++ < a_size)
			rra(a, b);
	}
	if (target[1] <= (b_size / 2))
	{
		while (target[1]-- >= 0)
			rb(a, b);
	}
	else
	{
		while (target[1]++ < b_size)
			rrb(a, b);
	}
}
