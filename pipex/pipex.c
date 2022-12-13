/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/13 17:22:23 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		execute_cmd(int argc, char **argv, char **envp, int cnt);
static int	fork_proc(int cmd_cnt, int *child_cnt, int pid);

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		statloc;
	int		child_cnt;
	pid_t	pid;

	child_cnt = -1;
	arguments_check(argc, argv);
	pipe(fd);
	pid = fork_proc(argc - 3, &child_cnt, 1);
	if (pid != 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, &statloc, WNOHANG);
	}
	else
	{
		if (child_cnt == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
		}
		else if (child_cnt == argc - 4)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
		}
		else
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
		}
		execute_cmd(argc, argv, envp, child_cnt + 2);
	}
}

static int	fork_proc(int cmd_cnt, int *child_cnt, int pid)
{
	if (*child_cnt >= cmd_cnt - 1 || pid == 0)
	{
		return (pid);
	}
	pid = fork();
	*child_cnt = *child_cnt + 1;
	return (fork_proc(cmd_cnt, child_cnt, pid));
}

void	execute_cmd(int argc, char **argv, char **envp, int cnt)
{
	char	*path;
	char	**arg;

	path = find_cmd_path(argv[cnt], envp);
	arg = ft_split(argv[cnt], ' ');
	free(arg[0]);
	arg[0] = ft_strdup(path);
	execve(path, arg, envp);
}
