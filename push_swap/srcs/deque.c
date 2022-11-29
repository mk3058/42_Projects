/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:28:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/29 13:02:02 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*create_deque(void)
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque -> head = NULL;
	deque -> tail = NULL;
	return (deque);
}

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> data = data;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	if (!new_node)
		return (NULL);
	return (new_node);
}

void	free_deque(t_deque *deque)
{
	t_node	*tmp;

	while (deque -> head)
	{
		tmp = deque -> head -> next;
		free (deque -> head);
		deque -> head = tmp;
	}
	free(deque);
}

int	deque_size(t_deque *deque)
{
	int		i;
	t_node	tmp;

	i = 0;
	tmp = deque -> head;
	while (tmp)
	{
		i++;
		tmp = tmp -> next;
	}
	return (i);
}