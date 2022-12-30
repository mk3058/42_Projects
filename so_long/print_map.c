/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:56:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/30 15:18:11 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_background(char **map, t_asset *a, t_window win);
static void	manage_asset(t_asset *a, void *mlx_ptr, int mode);
static void	set_object(char **map, t_asset *a, t_window win);

void	print_map(char **map, t_window win)
{
	t_asset	a[4];

	manage_asset(a, win.mlx_ptr, SET);
	set_background(map, a, win);
	set_object(map, a, win);
	manage_asset(a, win.mlx_ptr, FREE);
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

static void	manage_asset(t_asset *a, void *mlx_ptr, int mode)
{
	char	*d[4];
	t_asset	*c;

	d[TILE] = "./asset/tile.xpm";
	d[WALL] = "./asset/wall.xpm";
	d[ITEM] = "./asset/item.xpm";
	d[EXIT] = "./asset/exit.xpm";
	if (mode == SET)
	{
		c = a + TILE;
		c -> img = mlx_xpm_file_to_image(mlx_ptr, d[TILE], &c -> wd, &c -> hi);
		c = a + WALL;
		c -> img = mlx_xpm_file_to_image(mlx_ptr, d[WALL], &c -> wd, &c -> hi);
		c = a + ITEM;
		c -> img = mlx_xpm_file_to_image(mlx_ptr, d[ITEM], &c -> wd, &c -> hi);
		c = a + EXIT;
		c -> img = mlx_xpm_file_to_image(mlx_ptr, d[EXIT], &c -> wd, &c -> hi);
	}
	else if (mode == FREE)
	{
		mlx_destroy_image(mlx_ptr, a[TILE].img);
		mlx_destroy_image(mlx_ptr, a[WALL].img);
		mlx_destroy_image(mlx_ptr, a[ITEM].img);
		mlx_destroy_image(mlx_ptr, a[EXIT].img);
	}
}
