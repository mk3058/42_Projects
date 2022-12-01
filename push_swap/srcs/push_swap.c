/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:50 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/01 17:58:35 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	devide(t_deque *a, t_deque *b);

// input 중간에 문자열 있을 경우 처리 필요 1 2 3 "4 5" 6
int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;

	a = create_deque();
	b = create_deque();
	get_arguments(argc, argv, a, b);
	devide(a, b);
}

static void	devide(t_deque *a, t_deque *b)
{
	t_node	*tmp;
	int		i;
	int		deq_size;
	int		pivot[2];

	i = -1;
	deq_size = deque_size(a);
	pivot[0] = (int)((double)deq_size / 3 + 0.5);
	pivot[1] = (int)(((double)deq_size / 3) * 2 + 0.5);
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
