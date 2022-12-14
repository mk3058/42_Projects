/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/14 16:38:51 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_err(char *err_message, char *prefix, char *postfix)
{
	if (prefix)
		ft_printf("%s: ", prefix);
	if (err_message)
		ft_printf("%s", err_message);
	else
		ft_printf("%s", strerror(errno));
	if (postfix)
		ft_printf(": %s", postfix);
	ft_printf("\n");
	exit(EXIT_FAILURE);
}

void	arguments_check(int argc, char **argv)
{
	int	req_arg;

	if (is_equal(argv[1], "here_doc"))
		req_arg = 6;
	else
	{
		req_arg = 5;
		if (access(argv[1], R_OK) < 0)
			exit_err(NULL, NULL, NULL);
	}
	if (argc < req_arg)
		exit_err(strerror(EINVAL), NULL, NULL);
}
