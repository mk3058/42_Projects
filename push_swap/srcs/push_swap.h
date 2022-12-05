/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:28 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/05 11:31:31 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> /////////////////////////

void	alloc_check(t_deque *a, t_deque *b, void *alloc);
void	sort(t_deque *a, t_deque *b, int *target);
void	get_arguments(int argc, char **argv, t_deque *a, t_deque *b);
void	exit_err(t_deque *a, t_deque *b);
void	sa(t_deque *a, t_deque *b);
void	sb(t_deque *a, t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a, t_deque *b);
void	rb(t_deque *a, t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a, t_deque *b);
void	rrb(t_deque *a, t_deque *b);
void	rrr(t_deque *a, t_deque *b);
int		*count_cmd(t_deque *a, t_deque *b);

#endif