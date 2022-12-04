/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:56:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/04 18:13:07 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	push_head(t_deque *deque, t_node *node)
{
	if (!deque || !node)
		return ;
	if (!(deque -> head))
	{
		deque -> head = node;
		deque -> tail = node;
	}
	else
	{
		deque -> head -> prev = node;
		node -> next = deque -> head;
		deque -> head = node;
	}
}

void	push_tail(t_deque *deque, t_node *node)
{
	if (!deque || !node)
		return ;
	if (!(deque -> tail))
	{
		deque -> head = node;
		deque -> tail = node;
	}
	else
	{
		deque -> tail -> next = node;
		node -> prev = deque -> tail;
		deque -> tail = node;
	}
}

int	pop_head(t_deque *deque)
{
	int		data;
	t_node	*cur;

	cur = deque -> head;
	data = cur -> data;
	if (deque_size(deque) > 1)
	{	
		if (cur -> next)
			cur -> next -> prev = NULL;
		deque -> head = cur -> next;
		free(cur);
	}
	else
	{
		free(cur);
		deque -> head = NULL;
		deque -> tail = NULL;
	}
	return (data);
}

int	pop_tail(t_deque *deque)
{
	int		data;
	t_node	*cur;

	cur = deque -> tail;
	data = cur -> data;
	if (deque_size(deque) > 1)
	{
		if (cur -> prev)
			cur -> prev -> next = NULL;
		deque -> tail = cur -> prev;
		free(cur);
	}
	else
	{
		free(cur);
		deque -> head = NULL;
		deque -> tail = NULL;
	}
	return (data);
}

void	swap_data(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a -> data;
	a -> data = b -> data;
	b -> data = tmp;
	tmp = a -> cnt;
	a -> cnt = b -> cnt;
	b -> cnt = tmp;
}
