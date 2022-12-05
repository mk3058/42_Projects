/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:21 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/05 11:31:19 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_err(t_deque *a, t_deque *b)
{
	ft_putstr_fd("Error\n", 1);
	if (a && b)
	{
		free_deque(a);
		free_deque(b);
	}
	exit(EXIT_FAILURE);
}

void	alloc_check(t_deque *a, t_deque *b, void *alloc)
{
	if (!alloc)
		exit_err(a, b);
}
