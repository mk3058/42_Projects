/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:56:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/28 17:20:01 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	append_head(t_deque *deque, t_node *node)
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

void	append_tail(t_deque *deque, t_node *node)
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
	if (cur -> next)
		cur -> next -> prev = NULL;
	deque -> head = cur -> next;
	free(cur);
	return (data);
}

int	pop_tail(t_deque *deque)
{
	int		data;
	t_node	*cur;

	cur = deque -> tail;
	data = cur -> data;
	if (cur -> prev)
		cur -> prev -> next = NULL;
	deque -> tail = cur -> prev;
	free(cur);
	return (data);
}
