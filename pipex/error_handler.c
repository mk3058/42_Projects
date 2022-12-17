/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/17 00:10:41 by minkyu           ###   ########.fr       */
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
	int	i;

	i = -1;
	req_arg = 5;
	if (argc > 1 && is_equal(argv[1], "here_doc"))
		req_arg++;
	else if (argc > 1 && !is_equal(argv[1], "here_doc"))
	{
		if (access(argv[1], R_OK) < 0)
			exit_err(NULL, NULL, argv[1]);
	}
	if (argc < req_arg)
		exit_err(strerror(EINVAL), NULL, NULL);
}
