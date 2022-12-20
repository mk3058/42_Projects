/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/20 14:11:39 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_outfile_fd(int argc, char **argv)
{
	int	fd;

	if (is_equal(argv[0], "here_doc"))
		fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit_err(NULL, NULL, argv[argc - 1]);
	return (fd);
}

int	get_infile_fd(int argc, char **argv)
{
	int	fd;

	fd = -1;
	if (argc > 1)
	{
		if (access(argv[1], R_OK) < 0)
			exit_err(NULL, NULL, argv[1]);
		fd = open(argv[1], O_RDONLY);
	}
	if (fd < 0)
		exit_err(NULL, NULL, argv[1]);
	return (fd);
}
