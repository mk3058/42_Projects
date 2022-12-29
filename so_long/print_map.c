/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:56:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/30 00:51:49 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_background(char **map, t_asset a, t_window win);
static void	set_asset(t_asset *a, void *mlx_ptr);

void	print_map(char **map, t_window win)
{
	t_asset	a;

	set_asset(&a, win.mlx_ptr);
	set_background(map, a, win);
}

static void	set_background(char **map, t_asset a, t_window win)
{
	int	i;
	int	j;
	int	x;
	int	y;

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
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, a.wall, x, y);
			else
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, a.tile, x, y);
			x += 32;
		}
		y += 32;
	}
}

void	set_asset(t_asset *a, void *mlx_ptr)
{
	int	wd;
	int	hi;

	a -> tile = mlx_xpm_file_to_image(mlx_ptr, "./asset/tile.xpm", &wd, &hi);
	a -> wall = mlx_xpm_file_to_image(mlx_ptr, "./asset/wall.xpm", &wd, &hi);
	a -> item = mlx_xpm_file_to_image(mlx_ptr, "./asset/item.xpm", &wd, &hi);
	a -> door = mlx_xpm_file_to_image(mlx_ptr, "./asset/door.xpm", &wd, &hi);
}
