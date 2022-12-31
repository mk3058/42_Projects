/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/31 18:05:45 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEYPRESS 2
#define REDCROSS 17

static void	set_win_size(char **map, t_window *win);
static void	init_data(t_data *d, t_asset *a, t_player *p, t_window *w);
static int	close_program(t_data *d);

int	main(int argc, char **argv)
{
	t_window	win;
	t_data		d;
	t_asset		*a;
	t_player	*p;

	arguments_check(argc, argv);
	d.map = map_parser(argv[1]);
	set_win_size(d.map, &win);
	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.x, win.y, "!~~ so_long ~~!");
	init_game(d.map, &a, &p, win);
	init_data(&d, a, p, &win);
	mlx_hook(win.win_ptr, KEYPRESS, 1L << 0, key_check, &d);
	mlx_hook(win.win_ptr, REDCROSS, 1L << 0, close_program, &d);
	mlx_loop_hook(win.mlx_ptr, render_img, &d);
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

static void	init_data(t_data *d, t_asset *a, t_player *p, t_window *w)
{
	d -> key = ft_calloc(4, sizeof(int));
	d -> a = a;
	d -> p = p;
	d -> w = w;
}

static int	close_program(t_data *d)
{
	if (d != NULL)
		exit(0);
	return (0);
}
