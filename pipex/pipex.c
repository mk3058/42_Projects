/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:22:38 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/15 19:21:39 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	fork_proc(int cmd_cnt, int *child_cnt, int pid, int **fd);
static void	close_fd(int **fd, int proc_cnt, int child_cnt);
static void	clean(int **fd, int proc_cnt);

int	main(int argc, char **argv, char **envp)
{
	int		**fd;
	int		statloc;
	int		child_cnt;
	pid_t	pid;

	child_cnt = -1;
	arguments_check(argc, argv);
	if (is_equal(argv[1], "here_doc"))
		heredoc(&argc, &argv);
	fd = malloc(sizeof(int *) * (argc - 4));
	pid = fork_proc(argc - 3, &child_cnt, -1, fd);
	if (pid != 0)
	{
		close_fd(fd, argc - 3, -1);
		waitpid(pid, &statloc, 0);
		clean(fd, argc - 3);
	}
	else
		execute_cmd(argv, envp, child_cnt + 2, fd);
}

void	set_fd(int argc, char **argv, int **fd, int child_cnt)
{
	int	infile_fd;
	int	outfile_fd;
	int	proc_cnt;

	infile_fd = open(argv[1], O_RDONLY);
	outfile_fd = get_write_fd(argc, argv);
	if (infile_fd == -1 || outfile_fd == -1)
		exit_err(strerror(errno), NULL, NULL);
	proc_cnt = argc - 3;
	if (child_cnt == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[child_cnt][1], STDOUT_FILENO);
	}
	else if (child_cnt == proc_cnt - 1)
	{
		dup2(fd[child_cnt - 1][0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(fd[child_cnt - 1][0], STDIN_FILENO);
		dup2(fd[child_cnt][1], STDOUT_FILENO);
	}
	close_fd(fd, proc_cnt, child_cnt);
}

static void	close_fd(int **fd, int proc_cnt, int child_cnt)
{
	int	i;

	i = -1;
	while (++i < proc_cnt - 1)
	{
		if (i == child_cnt - 1)
			close(fd[i][1]);
		else if (i == child_cnt)
			close(fd[i][0]);
		else
		{
			close(fd[i][0]);
			close(fd[i][1]);
		}
	}
}

static int	fork_proc(int cmd_cnt, int *child_cnt, int pid, int **fd)
{
	int	i;
	int	statloc;

	i = -1;
	if (*child_cnt >= cmd_cnt - 1 || pid == 0)
		return (pid);
	if (pid == -1)
	{
		while (++i < cmd_cnt - 1)
		{
			fd[i] = malloc(sizeof(int) * 2);
			pipe(fd[i]);
		}
	}
	pid = fork();
	*child_cnt = *child_cnt + 1;
	waitpid(pid, &statloc, WNOHANG);
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
