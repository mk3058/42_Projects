/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:34:16 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/01 15:31:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_deque *a, t_deque *b)
{
	int	data;
	int	cnt;

	ft_putstr_fd("rrr\n", 1);
	cnt = a -> tail -> cnt;
	data = pop_tail(a);
	push_head(a, create_node(data));
	a -> head -> cnt = cnt;
	cnt = b -> tail -> cnt;
	data = pop_tail(b);
	push_head(b, create_node(data));
	b -> head -> cnt = cnt;
}
