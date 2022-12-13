/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/12 15:12:38 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(int argc, char **argv, char **envp, int cnt);

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		statloc;
	pid_t	pid;

	pid = 0;
	arguments_check(argc, argv);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(argc, argv, envp, 2);
	}
	else
	{
		wait(&statloc);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execute_cmd(argc, argv, envp, 3);
	}
}

void	execute_cmd(int argc, char **argv, char **envp, int cnt)
{
	char	*path;
	char	**arg;

	path = cmd_path(argv[cnt], envp);
	arg = ft_split(argv[cnt], ' ');
	free(arg[0]);
	arg[0] = ft_strdup(path);
	execve(path, arg, envp);
}
