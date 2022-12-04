/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:27:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/12/04 10:51:46 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int num);

int  *count_cmd(t_deque *a, t_deque *b)
{
	int	*cmd_num;
	t_node	*a_tmp;
	t_node	*b_tmp;
	int	b_size;
	int	a_size;
	int	a_ind;
	int b_ind;
	int	a_cnt;
	int	a_target;

	b_ind = 0;
	a_tmp = a -> head;
	b_tmp = b -> head;
	b_size = deque_size(b);
	a_size = deque_size(a);
	cmd_num = malloc(sizeof(int) * b_size);
	if (!cmd_num)
		return (NULL);
	while (b_ind < b_size)
	{
		cmd_num[b_ind] = ft_abs(b_ind - (b_ind > b_size / 2) * b_size);
		b_ind++;
	}
	b_ind = 0;
	while (b_tmp)
	{
		a_tmp = a -> head;
		a_ind = 0;
		a_cnt = INT_MAX;
		a_target = 0;
		while (a_tmp)
		{
			if (((a_tmp -> cnt) > (b_tmp -> cnt)) && (a_tmp -> cnt) < a_cnt)
			{
				a_cnt = a_tmp -> cnt;
				a_target = a_ind;
			}
			a_ind++;
			a_tmp = a_tmp -> next;
		}
		if (a_target == INT_MAX)
			a_target = 0;
		cmd_num[b_ind++] += ft_abs(a_target - (a_target > a_size /2) * a_size);
		b_tmp = b_tmp -> next;
	}
	return (cmd_num);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num); 
}