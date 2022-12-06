/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:10:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 22:16:38 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	cnt = a -> head -> cnt;
	data = pop_head(a);
	push_tail(a, create_node(data));
	a -> tail -> cnt = cnt;
}

void	rb(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	cnt = b -> head -> cnt;
	data = pop_head(b);
	push_tail(b, create_node(data));
	b -> tail -> cnt = cnt;
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	cnt = a -> head -> cnt;
	data = pop_head(a);
	push_tail(a, create_node(data));
	a -> tail -> cnt = cnt;
	cnt = b -> head -> cnt;
	data = pop_head(b);
	push_tail(b, create_node(data));
	b -> tail -> cnt = cnt;
}

void	rra(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	cnt = a -> tail -> cnt;
	data = pop_tail(a);
	push_head(a, create_node(data));
	a -> head -> cnt = cnt;
}

void	rrb(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	cnt = b -> tail -> cnt;
	data = pop_tail(b);
	push_head(b, create_node(data));
	b -> head -> cnt = cnt;
}
