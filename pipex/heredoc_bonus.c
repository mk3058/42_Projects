/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:39:02 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/19 17:42:02 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	heredoc(int *argc, char ***argv)
{
	int		fd;
	char	*input;
	char	*limiter;

	fd = open(".heredoc_tmp", O_RDWR | O_TRUNC | O_CREAT, 777);
	limiter = ft_strjoin((*argv)[2], "\n");
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
		if (is_equal(limiter, input))
			break ;
		ft_putstr_fd(input, fd);
		free(input);
	}
	free(limiter);
	free(input);
	close(fd);
	*argc = *argc -1;
	(*argv)[2] = ".heredoc_tmp";
	(*argv) = (*argv) + 1;
}

int	is_equal(char *str1, char *str2)
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
