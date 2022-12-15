/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:15:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/15 16:21:39 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_write_fd(int argc, char **argv)
{
	int	fd;

	if (is_equal(argv[0], "here_doc"))
		fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	return (fd);
}
