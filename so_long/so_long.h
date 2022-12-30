/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:44:33 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/30 17:01:20 by minkyuki         ###   ########.fr       */
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

# define TILE 0
# define WALL 1
# define ITEM 2
# define EXIT 3

typedef struct s_asset
{
	void	*img;
	int		wd;
	int		hi;
}	t_asset;

typedef struct s_player
{
	void	*img;
	int		wd;
	int		hi;
	int		x;
	int		y;
}	t_player;

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
void	init_game(char **map, t_asset **a, t_player **p, t_window win);

#endif