/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:57:03 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 15:36:14 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a, t_deque *b)
{
	int	cnt;

	if (deque_size(a) > 1)
	{
		ft_putstr_fd("sa\n", 1);
		swap_data(a -> head, a -> head -> next);
	}
}

void	sb(t_deque *a, t_deque *b)
{
	int	cnt;

	if (deque_size(b) > 1)
	{
		ft_putstr_fd("sb\n", 1);
		swap_data(b -> head, b -> head -> next);
	}
}

void	ss(t_deque *a, t_deque *b)
{
	int	cnt;

	if (deque_size(a) > 1 && deque_size(b) > 1)
	{
		ft_putstr_fd("ss\n", 1);
		swap_data(a -> head, a -> head -> next);
		swap_data(b -> head, b -> head -> next);
	}
}

void	pa(t_deque *a, t_deque *b)
{
	t_node	*new_node;
	int		data;
	int		cnt;

	if (deque_size(b) > 0)
	{
		ft_putstr_fd("pa\n", 1);
		cnt = b -> head -> cnt;
		data = pop_head(b);
		new_node = create_node(data);
		new_node -> cnt = cnt;
		push_head(a, new_node);
	}
}

void	pb(t_deque *a, t_deque *b)
{
	t_node	*new_node;
	int		data;
	int		cnt;

	if (deque_size(a) > 0)
	{
		ft_putstr_fd("pb\n", 1);
		cnt = a -> head -> cnt;
		data = pop_head(a);
		new_node = create_node(data);
		new_node -> cnt = cnt;
		push_head(b, new_node);
	}
}
