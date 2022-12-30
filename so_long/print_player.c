/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:18:37 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/30 16:34:12 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_player(char **map, t_window win)
{
	t_player	p;
	char		*dir;

	dir = "./asset/player.xpm";
	p.img = mlx_xpm_file_to_image(win.mlx_ptr, dir, p.wd, p.hi);
}

static void	init_player(char **map, t_player *p, t_window win)
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
			if (map[i][j] == 'P')
				mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, cur.img, x, y);
			x += 32;
		}
		y += 32;
	}
}