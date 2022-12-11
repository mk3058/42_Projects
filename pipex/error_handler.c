/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/11 17:26:24 by minkyuki         ###   ########.fr       */
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
