/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:56:34 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/29 20:29:23 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map, t_window win)
{
	t_asset	a;
	void	*mlx_ptr;

	mlx_ptr = win.mlx_ptr;
	a.tile = mlx_xpm_file_to_image(mlx_ptr, "./asset/tile.xpm", &a.wd, &a.hi);
	a.wall = mlx_xpm_file_to_image(mlx_ptr, "./asset/wall.xpm", &a.wd, &a.hi);
	a.item = mlx_xpm_file_to_image(mlx_ptr, "./asset/item.xpm", &a.wd, &a.hi);
	a.door = mlx_xpm_file_to_image(mlx_ptr, "./asset/door.xpm", &a.wd, &a.hi);
}