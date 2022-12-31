/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 12:26:47 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/31 14:13:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2

static int	set_point(t_player *p, char **map, int *k);
static void	move_player(void *mlx, void *win, t_asset *a, t_data *d);

int	key_check(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data -> w -> mlx_ptr, data -> w -> win_ptr);
		exit(0);
	}
	else if (keycode == W)
		(data -> key)[UP] = 1;
	else if (keycode == A)
		(data -> key)[LEFT] = 1;
	else if (keycode == S)
		(data -> key)[DOWN] = 1;
	else if (keycode == D)
		(data -> key)[RIGHT] = 1;
	return (0);
}

int	render_img(t_data *d)
{
	int	i;

	i = -1;
	move_player(d -> w -> mlx_ptr, d -> w -> win_ptr, d -> a, d);
	while (++i < 4)
		(d -> key)[i] = 0;
	return (0);
}

static void	move_player(void *mlx, void *win, t_asset *a, t_data *d)
{
	static int	item_cnt;
	char		**map;
	t_player	*p;

	map = d -> map;
	p = d -> p;
	if (map[(p -> y) / 32][(p -> x) / 32] != 'E')
		mlx_put_image_to_window(mlx, win, (a + TILE)-> img, p -> x, p -> y);
	else
	{
		if (item_cnt == 7)
		{
			mlx_destroy_window(mlx, win);
			exit(0);
		}
		mlx_put_image_to_window(mlx, win, (a + EXIT)-> img, p -> x, p -> y);
	}
	item_cnt += set_point(p, map, d -> key);
	mlx_put_image_to_window(mlx, win, p -> img, p -> x, p -> y);
}

static int	set_point(t_player *p, char **map, int *k)
{
	static int	move_cnt;
	int			move_to;
	int			move_x;
	int			move_y;

	move_to = k[UP] * 1 + k[DOWN] * 2 + k[LEFT] * 3 + k[RIGHT] * 4;
	if (move_to-- == 0)
		return (0);
	move_x = p -> x;
	move_y = p -> y;
	move_x = (move_x) - ((move_to == LEFT) * 32) + ((move_to == RIGHT) * 32);
	move_y = (move_y) - ((move_to == UP) * 32) + ((move_to == DOWN) * 32);
	if (map[(move_y) / 32][(move_x) / 32] != '1')
	{
		p -> x = move_x;
		p -> y = move_y;
		ft_printf("Move count : %3d\n", ++move_cnt);
		if (map[(move_y) / 32][(move_x) / 32] == 'C')
		{
			map[(move_y) / 32][(move_x) / 32] = '0';
			return (1);
		}
	}
	return (0);
}
