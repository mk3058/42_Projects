/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:49:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/07 21:28:14 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deque/deque.h"
#include "../get_next_line/get_next_line.h"
#include "../push_swap.h"

static void	sort_cmd(t_deque *a, t_deque *b, char *cmd);
static void	rm_nl(char *str);
static int	is_equal(char *str1, char *str2);

int	main(int argc, char **argv)
{
	t_deque	*a;
	t_deque	*b;
	char	*cmd;

	a = create_deque();
	b = create_deque();
	get_arguments(argc, argv, a, b);
	cmd = get_next_line(0);
	while (cmd)
	{
		rm_nl(cmd);
		sort_cmd(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_asc(a) && !deque_size(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_deque(a);
	free_deque(b);
	return (0);
}

static void	sort_cmd(t_deque *a, t_deque *b, char *cmd)
{
	if (is_equal(cmd, "sa"))
		sa(a, b);
	else if (is_equal(cmd, "sb"))
		sb(a, b);
	else if (is_equal(cmd, "ss"))
		ss(a, b);
	else if (is_equal(cmd, "pa"))
		pa(a, b);
	else if (is_equal(cmd, "pb"))
		pb(a, b);
	else if (is_equal(cmd, "ra"))
		ra(a, b);
	else if (is_equal(cmd, "rb"))
		rb(a, b);
	else if (is_equal(cmd, "rr"))
		rr(a, b);
	else if (is_equal(cmd, "rra"))
		rra(a, b);
	else if (is_equal(cmd, "rrb"))
		rrb(a, b);
	else if (is_equal(cmd, "rrr"))
		rrr(a, b);
	else
		exit_err(a, b);
}

static void	rm_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
}

static int	is_equal(char *str1, char *str2)
{
	int	i;
	int	diff;

	i = 0;
	diff = 0;
	while (str1[i] || str2[i])
	{
		diff = str1[i] - str2[i];
		if (diff != 0)
			return (0);
		i++;
	}
	return (1);
}
