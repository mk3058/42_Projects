/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:36:19 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/19 17:42:02 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**set_pipe(int argc, char **argv)
{
	int	**fd;
	int	i;

	i = -1;
	fd = malloc(sizeof(int *) * (argc - 4));
	while (++i < argc - 4)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
	}
	return (fd);
}

int	set_fd(int argc, char **argv, int **fd, int child_cnt)
{
	int	file_fd;
	int	proc_cnt;
	int	std_out;

	proc_cnt = argc - 3;
	std_out = dup(STDOUT_FILENO);
	close_fd(fd, proc_cnt, child_cnt);
	if (child_cnt == 0)
	{
		file_fd = get_infile_fd(argc, argv);
		dup2(file_fd, STDIN_FILENO);
		dup2(fd[child_cnt][1], STDOUT_FILENO);
	}
	else if (child_cnt == proc_cnt - 1)
	{
		file_fd = get_outfile_fd(argc, argv);
		dup2(fd[child_cnt - 1][0], STDIN_FILENO);
		dup2(file_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(fd[child_cnt - 1][0], STDIN_FILENO);
		dup2(fd[child_cnt][1], STDOUT_FILENO);
	}
	return (std_out);
}

void	close_fd(int **fd, int proc_cnt, int child_cnt)
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