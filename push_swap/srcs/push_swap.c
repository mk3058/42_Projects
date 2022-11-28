/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:50 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/28 17:31:57 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	int		i;

	if (argc < 2)
	{
		ft_putstr_fd("Invalid arguments\n", 1);
		exit(EXIT_FAILURE);
	}
	a = create_deque();
	b = create_deque();
	i = 0;
	while (++i < argc)
		append_tail(a, create_node(ft_atoi(argv[i])));
}
