/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/13 11:51:21 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_err(int mode)
{
	if (mode == PRINT)
		ft_printf("%s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	arguments_check(int argc, char **argv)
{
	if (argc < 5)
		exit_err(QUIET);
	if (access(argv[1], R_OK) < 0)
		exit_err(PRINT);
}
