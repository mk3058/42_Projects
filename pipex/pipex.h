/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:19:36 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/23 10:28:36 by minkyu           ###   ########.fr       */
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
# include <errno.h>
# include <string.h>

void	exit_err(char *err_message, char *prefix, char *postfix);
void	arguments_check(int argc, char **argv);
void	execute_cmd(char **argv, char **envp, int cnt, int **fd);
void	heredoc(int *argc, char ***argv);
int		is_equal(char *str1, char *str2);
int		**set_pipe(int argc);
int		set_fd(int argc, char **argv, int **fd, int child_cnt);
void	close_fd(int **fd, int proc_cnt, int child_cnt);
int		get_infile_fd(int argc, char **argv);
int		get_outfile_fd(int argc, char **argv);

#endif