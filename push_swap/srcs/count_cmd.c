/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:27:36 by minkyu            #+#    #+#             */
/*   Updated: 2022/12/06 17:31:51 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	req_cmd_a(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd);
static void	req_cmd_b(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd);
static int	find_a_ind(t_deque *a, t_deque *b, int *target, int *cmd_num);
static int	find_target(t_node *tmp, t_node *b_tmp);

int	*count_cmd(t_deque *a, t_deque *b)
{
	int	*cmd_num;
	int	*target;
	int	b_size;
	int	min;
	int	i;

	i = 0;
	b_size = deque_size(b);
	cmd_num = malloc(sizeof(int) * b_size);
	target = ft_calloc(2, sizeof(int));
	if (!cmd_num || !target)
		return (NULL);
	req_cmd_b(a -> head, b -> head, b_size, cmd_num);
	req_cmd_a(a -> head, b -> head, deque_size(a), cmd_num);
	min = cmd_num[0];
	while (++i < b_size)
	{
		if (min > cmd_num[i])
		{
			min = cmd_num[i];
			target[1] = i;
		}
	}
	target[0] = find_a_ind(a, b, target, cmd_num);
	return (target);
}

static void	req_cmd_a(t_node *a_tmp, t_node *b_tmp, int a_size, int *cmd)
{
	int		b_ind;
	int		target_ind;
	t_node	*tmp;

	b_ind = 0;
	while (b_tmp)
	{
		target_ind = find_target(a_tmp, b_tmp);
		cmd[b_ind++] += ft_abs(target_ind - (target_ind > a_size / 2) * a_size);
		b_tmp = b_tmp -> next;
	}
}

static int	find_target(t_node *tmp, t_node *b_tmp)
{
	int	target_ind;
	int	target_cnt;
	int	a_ind;

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

static int	find_a_ind(t_deque *a, t_deque *b, int *target, int *cmd_num)
{
	t_node	*tmp;
	int		b_cnt;
	int		target_cnt;
	int		target_ind;
	int		a_ind;

	tmp = a -> head;
	b_cnt = get_cnt(b, target[1]);
	a_ind = 0;
	target_cnt = INT_MAX;
	target_ind = 0;
	while (tmp)
	{
		if ((tmp -> cnt) > b_cnt && (tmp -> cnt) < target_cnt)
		{
			target_cnt = tmp -> cnt;
			target_ind = a_ind;
		}
		a_ind++;
		tmp = tmp -> next;
	}
	if (target_cnt == INT_MAX)
		target_ind = find_max(a) + 1;
	free(cmd_num);
	return (target_ind);
}
