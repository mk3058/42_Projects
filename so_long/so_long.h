/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:33 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/29 20:26:01 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>

# include <stdio.h> ////////////////////////////

# define EXIT_CNT 0
# define ITEM_CNT 1
# define START_POINT_CNT 2

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_asset
{
	void	*tile;
	void	*wall;
	void	*item;
	void	*door;
	int		wd;
	int		hi;
}	t_asset;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}	t_window;

void	exit_err(char *err_message, char *prefix, char *postfix);
void	arguments_check(int argc, char **argv);
char	**map_parser(char *map_path);

#endif