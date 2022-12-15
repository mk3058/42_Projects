/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:19:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/15 15:35:55 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf_bonus.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

void	exit_err(char *err_message, char *prefix, char *postfix);
void	execute_cmd(int argc, char **argv, char **envp, int cnt, int **fd);
void	set_fd(int argc, char **argv, int **fd, int child_cnt);
void	arguments_check(int argc, char **argv);
void	heredoc(int *argc, char ***argv);
int		is_equal(char *str1, char *str2);
int		get_write_fd(int argc, char **argv);

#endif