/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/14 15:08:26 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_err(int mode)
{
	if (mode == PRINT)
		ft_printf("%s\n", strerror(errno));
	else if (mode == FEWARG)
		ft_printf("%s\n", strerror(EINVAL));
	exit(EXIT_FAILURE);
}

void	arguments_check(int argc, char **argv)
{
	int	req_arg;

	req_arg = 5;
	if (is_equal(argv[1], "here_doc"))
		req_arg++;
	else
		if (access(argv[1], R_OK) < 0)
			exit_err(PRINT);
	if (argc < req_arg)
		exit_err(FEWARG);
}
