/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:54:52 by minkyuki          #+#    #+#             */
/*   Updated: 2023/08/11 12:55:18 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <stdio.h>

void	o_add(t_object **head, t_object *new)
{
	t_object	*cur;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
}

t_object	*o_last(t_object *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}