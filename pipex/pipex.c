/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/20 14:10:36 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fork_proc(int cmd_cnt, int *child_cnt, int *pid, int **fd);
static void	clean(int **fd, int proc_cnt);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		**fd;
	int		statloc;
	int		child_cnt;
	pid_t	*pid;

	i = -1;
	child_cnt = -1;
	arguments_check(argc, argv);
	if (is_equal(argv[1], "here_doc"))
		heredoc(&argc, &argv);
	fd = set_pipe(argc);
	pid = malloc(sizeof(int *) * (argc - 3));
	if (fork_proc(argc - 3, &child_cnt, pid, fd) != 0)
	{
		close_fd(fd, argc - 3, -1);
		while (++i < argc - 3)
			waitpid(pid[i], &statloc, 0);
		clean(fd, argc - 3);
		return (WEXITSTATUS(statloc));
	}
	else
		execute_cmd(argv, envp, child_cnt + 2, fd);
}

static int	fork_proc(int cmd_cnt, int *child_cnt, int *pid, int **fd)
{
	int	i;

	i = -1;
	if (*child_cnt >= cmd_cnt - 1 || (*child_cnt >= 0 && pid[*child_cnt] == 0))
		return (pid[*child_cnt]);
	*child_cnt = *child_cnt + 1;
	pid[*child_cnt] = fork();
	return (fork_proc(cmd_cnt, child_cnt, pid, fd));
}

static void	clean(int **fd, int proc_cnt)
{
	int	i;

	i = -1;
	while (++i < proc_cnt - 1)
		free(fd[i]);
	free(fd);
	unlink(".heredoc_tmp");
}
