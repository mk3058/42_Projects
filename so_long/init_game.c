/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:56:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/31 17:02:17 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_background(char **map, t_asset *a, t_window win);
static void	set_object(char **map, t_asset *a, t_window win);
static void	set_player(char **map, t_player *p, t_window win);
static void	init_asset(t_asset *a, t_player *p, void *mlx_ptr);

void	init_game(char **map, t_asset **a, t_player **p, t_window win)
{
	*a = malloc(sizeof(t_asset) * 4);
	*p = malloc(sizeof(t_player));
	init_asset(*a, *p, win.mlx_ptr);
	set_background(map, *a, win);
	set_object(map, *a, win);
	set_player(map, *p, win);
}

static void	set_background(char **map, t_asset *a, t_window win)
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_asset	cur;

	i = -1;
	x = 0;
	y = 0;
	while (map[++i])
	{
		j = -1;
		x = 0;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				cur = a[WALL];
			else
				cur = a[TILE];
			mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, cur.img, x, y);
			x += cur.wd;
		}
		y += cur.hi;
	}
}

static void	set_object(char **map, t_asset *a, t_window win)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*mlx;

	i = -1;
	x = 0;
	y = 0;
	mlx = win.mlx_ptr;
	while (map[++i])
	{
		j = -1;
		x = 0;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win.win_ptr, a[ITEM].img, x, y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win.win_ptr, a[EXIT].img, x, y);
			x += 32;
		}
		y += 32;
	}
}

static void	set_player(char **map, t_player *p, t_window win)
{
	int		i;
	int		flag;
	void	*mlx;
	void	*wi_p;

	flag = 1;
	mlx = win.mlx_ptr;
	wi_p = win.win_ptr;
	while (*map && flag)
	{
		i = -1;
		p -> x = -32;
		p -> y += 32;
		while ((*map)[++i])
		{
			p -> x += 32;
			if ((*map)[i] == 'P')
			{
				mlx_put_image_to_window(mlx, wi_p, p -> img, p -> x, p -> y);
				flag = 0;
				break ;
			}
		}
		map++;
	}
}

static void	init_asset(t_asset *a, t_player *p, void *mlx_ptr)
{
	char	*d[4];
	char	*ply_d;
	t_asset	*c;

	d[TILE] = "./asset/tile.xpm";
	d[WALL] = "./asset/wall.xpm";
	d[ITEM] = "./asset/item.xpm";
	d[EXIT] = "./asset/exit.xpm";
	ply_d = "./asset/player.xpm";
	c = a + TILE;
	c -> img = mlx_xpm_file_to_image(mlx_ptr, d[TILE], &c -> wd, &c -> hi);
	c = a + WALL;
	c -> img = mlx_xpm_file_to_image(mlx_ptr, d[WALL], &c -> wd, &c -> hi);
	c = a + ITEM;
	c -> img = mlx_xpm_file_to_image(mlx_ptr, d[ITEM], &c -> wd, &c -> hi);
	c = a + EXIT;
	c -> img = mlx_xpm_file_to_image(mlx_ptr, d[EXIT], &c -> wd, &c -> hi);
	p -> img = mlx_xpm_file_to_image(mlx_ptr, ply_d, &p -> wd, &p -> hi);
	p -> x = -32;
	p -> y = -32;
}
