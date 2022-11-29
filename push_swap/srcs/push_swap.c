/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:50 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/29 11:49:36 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	int		i;

	arguments_check(argc, argv);
	a = create_deque();
	b = create_deque();
	i = 0;
	while (++i < argc)
		push_tail(a, create_node(ft_atoi(argv[i])));

	while(a -> head)
	{
		printf("%d\n", a -> head -> data);
		a -> head = a -> head -> next;
	}
}