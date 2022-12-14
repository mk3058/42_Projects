/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:39:02 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/14 14:37:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(char *limiter)
{
	int		fd;
	char	*input;

	fd = open(".heredoc_tmp", O_RDWR | O_CREAT | O_TRUNC, 777);
	limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		input = get_next_line(STDIN_FILENO);
		if (is_equal(limiter, input))
			break ;
		ft_putstr_fd(input, fd);
	}
	free(limiter);
	close(fd);
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
