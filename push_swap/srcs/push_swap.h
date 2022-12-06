/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:28 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 17:02:20 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "deque.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>

int		find_min(t_deque *deque);
int		is_asc(t_deque *deque);
void	manual_sort(t_deque *a, t_deque *b);
void	alloc_check(t_deque *a, t_deque *b, void *alloc);
void	sort(t_deque *a, t_deque *b, int *target);
void	get_arguments(int argc, char **argv, t_deque *a, t_deque *b);
void	exit_err(t_deque *a, t_deque *b);
void	exit_free(t_deque *a, t_deque *b);
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
int		ft_abs(int num);

#endif