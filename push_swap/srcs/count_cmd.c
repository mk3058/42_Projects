/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:27:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/12/04 14:36:19 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	req_cmd_a(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd);
static void	req_cmd_b(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd);
static int	ft_abs(int num);

int	*count_cmd(t_deque *a, t_deque *b)
{
	int	*cmd_num;
	int	*target;
	int	b_size;
	int	min;
	int	i;

	i = -1;
	b_size = deque_size(b);
	cmd_num = malloc(sizeof(int) * b_size);
	target = malloc(sizeof(int) * 2);
	if (!cmd_num)
		return (NULL);
	target[0] = req_cmd_a(a -> head, b -> head, deque_size(a), cmd_num);
	req_cmd_b(a -> head, b -> head, b_size, cmd_num);
	min = -1;
	while (++i < b_size)
		if (min > cmd_num[i])
			target[1] = i;
	free(cmd_num);
	return (target);
}

static int	req_cmd_a(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd)
{
	int		a_ind;
	int		b_ind;
	int		target_cnt;
	int		target_ind;
	t_node	*tmp;

	b_ind = 0;
	while (b_tmp)
	{
		tmp = a_tmp;
		a_ind = 0;
		target_cnt = INT_MAX;
		target_ind = 0;
		while (tmp)
		{
			if ((tmp -> cnt) > (b_tmp -> cnt) && (tmp -> cnt) < target_cnt)
			{
				target_cnt = tmp -> cnt;
				target_ind = a_ind;
			}
			a_ind++;
			tmp = tmp -> next;
		}
		cmd[b_ind++] += ft_abs(target_ind - (target_ind > a_size / 2) * a_size);
		b_tmp = b_tmp -> next;
	}
	return (target_ind);
}

static void	req_cmd_b(t_node *a_tmp, t_node *b_tmp, int b_size, int *cmd)
{
	int		b_ind;

	b_ind = 0;
	while (b_ind < b_size)
	{
		cmd[b_ind] = ft_abs(b_ind - (b_ind > b_size / 2) * b_size);
		b_ind++;
	}
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}
