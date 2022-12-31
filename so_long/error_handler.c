/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:16:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/31 14:16:24 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(char *err_message, char *prefix, char *postfix)
{
	if (prefix)
		ft_putstr_fd(prefix, 1);
	if (err_message)
		ft_putstr_fd(err_message, 1);
	else
		ft_putstr_fd(strerror(errno), 1);
	if (postfix)
		ft_putstr_fd(postfix, 1);
	ft_putstr_fd("\n", 1);
	exit(EXIT_FAILURE);
}

void	arguments_check(int argc, char **argv)
{
	int	len;
	
	if (argc != 2)
		exit_err(strerror(EINVAL), NULL, NULL);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".ber", 3))
		exit_err("Error\n", NULL, "Map must be .ber file");
}
