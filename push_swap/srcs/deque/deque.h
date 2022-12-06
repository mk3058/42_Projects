/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:24:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 18:09:06 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				cnt;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
}	t_deque;

t_deque	*create_deque(void);
t_node	*create_node(int data);
void	push_head(t_deque *deque, t_node *node);
void	push_tail(t_deque *deque, t_node *node);
int		pop_head(t_deque *deque);
int		pop_tail(t_deque *deque);
void	free_deque(t_deque *deque);
void	swap_data(t_node *a, t_node *b);
int		deque_size(t_deque *deque);
int		get_cnt(t_deque *deque, int index);

#endif