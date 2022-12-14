/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:19:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/14 15:02:35 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define QUIET 0
# define PRINT 1
# define FEWARG 2

void	exit_err(int mode);
char	*find_cmd_path(char	*cmd, char **envp);
void	arguments_check(int argc, char **argv);
void	heredoc(char *limiter);
int		is_equal(char *str1, char *str2);

#endif