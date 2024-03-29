/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:18:21 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 22:25:41 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_err(t_deque *a, t_deque *b)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_deque(a);
	if (b)
		free_deque(b);
	exit(EXIT_FAILURE);
}

void	exit_free(t_deque *a, t_deque *b)
{
	if (a)
		free_deque(a);
	if (b)
		free_deque(b);
	exit(EXIT_FAILURE);
}

void	alloc_check(t_deque *a, t_deque *b, void *alloc)
{
	if (!alloc)
		exit_err(a, b);
}
