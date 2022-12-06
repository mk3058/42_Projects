/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:50 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 17:00:55 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	devide(t_deque *a, t_deque *b);
static void	get_pivot(int *pivot, t_deque *a);
static void	rotate(t_deque *a, t_deque *b);

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	int		*target;

	a = create_deque();
	b = create_deque();
	get_arguments(argc, argv, a, b);
	if (deque_size(a) <= 5 && !is_asc(a))
		manual_sort(a, b);
	else if (deque_size(a) > 5 && !is_asc(a))
	{
		devide(a, b);
		pa(a, b);
		while (b -> head)
		{
			target = count_cmd(a, b);
			sort(a, b, target);
			free(target);
		}
		rotate(a, b);
	}
	free_deque(a);
	free_deque(b);
	return (0);
}

static void	devide(t_deque *a, t_deque *b)
{
	t_node	*tmp;
	int		i;
	int		deq_size;
	int		pivot[2];

	i = -1;
	deq_size = deque_size(a);
	get_pivot(pivot, a);
	while (++i < deq_size)
	{
		tmp = a -> head;
		if ((tmp -> cnt) <= pivot[0])
		{
			pb(a, b);
			rb(a, b);
		}
		else if (pivot[0] < (tmp -> cnt) && (tmp -> cnt) <= pivot[1])
			pb(a, b);
		else
			ra(a, b);
	}
	deq_size = deque_size(a);
	i = 0;
	while (i++ < deq_size)
		pb(a, b);
}

static void	get_pivot(int *pivot, t_deque *a)
{
	int	deq_size;

	deq_size = deque_size(a);
	pivot[0] = (int)((double)deq_size / 3 + 0.5);
	pivot[1] = (int)(((double)deq_size / 3) * 2 + 0.5);
}

static void	rotate(t_deque *a, t_deque *b)
{
	int		ind;
	int		deq_size;
	t_node	*tmp;

	ind = 0;
	tmp = a -> head;
	deq_size = deque_size(a);
	while (tmp -> cnt != 1)
	{
		ind++;
		tmp = tmp -> next;
	}
	if (ind <= deq_size / 2)
	{
		while (a -> head -> cnt != 1)
			ra(a, b);
	}
	else
	{
		while (a -> head -> cnt != 1)
			rra(a, b);
	}
}
