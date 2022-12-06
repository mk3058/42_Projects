/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:49:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/06 18:24:29 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../deque/deque.h"
# include "../get_next_line/get_next_line.h"
# include "../push_swap.h"

static void	sort_cmd(t_deque *a, t_deque *b, char *cmd);

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
		sort_cmd(a, b, cmd);
		cmd = get_next_line(0);
	}
	if (is_asc(a) && !deque_size(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

static void	sort_cmd(t_deque *a, t_deque *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", ft_strlen(cmd)))
		sa(a, b);
	else if (!ft_strncmp(cmd, "sb", ft_strlen(cmd)))
		sb(a, b);
	else if (!ft_strncmp(cmd, "ss", ft_strlen(cmd)))
		ss(a, b);
	else if (!ft_strncmp(cmd, "pa", ft_strlen(cmd)))
		pa(a, b);
	else if (!ft_strncmp(cmd, "pb", ft_strlen(cmd)))
		pb(a, b);
	else if (!ft_strncmp(cmd, "ra", ft_strlen(cmd)))
		ra(a, b);
	else if (!ft_strncmp(cmd, "rb", ft_strlen(cmd)))
		rb(a, b);
	else if (!ft_strncmp(cmd, "rr", ft_strlen(cmd)))
		rr(a, b);
	else if (!ft_strncmp(cmd, "rra", ft_strlen(cmd)))
		rra(a, b);
	else if (!ft_strncmp(cmd, "rrb", ft_strlen(cmd)))
		rrb(a, b);
	else if (!ft_strncmp(cmd, "rrr", ft_strlen(cmd)))
		rrr(a, b);
	else
		exit_err(a, b);
}
