/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/30 11:23:32 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_win_size(char **map, t_window *win);

int	main(int argc, char **argv)
{
	t_window	win;
	char		**map;

	arguments_check(argc, argv);
	map = map_parser(argv[1]);
	set_win_size(map, &win);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.x, win.y, "!~~ so_long ~~!");
	print_map(map, win);
	mlx_loop(win.mlx_ptr);
}

static void	set_win_size(char **map, t_window *win)
{
	int	map_width;
	int	map_height;

	map_width = ft_strlen(map[0]);
	map_height = 0;
	while (map[map_height])
		map_height++;
	win -> x = 32 * map_width;
	win -> y = 32 * map_height;
}
