/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:23 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/29 19:28:48 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *map_path);
static void	map_checker(char **map);
static void	component_check(char **map);

char	**map_parser(char *map_path)
{
	int		i;
	int		map_height;
	int		fd;
	char	**map;
	char	*line;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_err(NULL, NULL, NULL);
	map_height = get_map_height(map_path);
	map = ft_calloc(map_height + 1, sizeof(char *));
	while (i < map_height)
	{
		line = get_next_line(fd);
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map_checker(map);
	close(fd);
	return (map);
}

static int	get_map_height(char *map_path)
{
	int	height;
	int	fd;

	fd = open(map_path, O_RDONLY);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

static void	map_checker(char **map)
{
	int	map_width;
	int	i;
	int	j;

	map_width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		j = -1;
		if (ft_strlen(map[i]) != map_width)
			exit_err("Error\n", NULL, "Map must be rectangular!");
		if (i == 0 || map[i + 1] == (char *) '\0')
		{
			while (map[i][++j])
				if (map[i][j] != '1')
					exit_err("Error\n", NULL, "Invalid map format!");
		}
		else
			if (map[i][0] != '1' || map[i][map_width - 1] != '1')
				exit_err("Error\n", NULL, "Invalid map format!");
	}
	component_check(map);
}

static void	component_check(char **map)
{
	int	*req_com;
	int	i;
	int	j;

	req_com = ft_calloc(3, sizeof(int));
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'E')
				req_com[EXIT_CNT]++;
			else if (map[j][i] == 'C')
				req_com[ITEM_CNT]++;
			else if (map[j][i] == 'P')
				req_com[START_POINT_CNT]++;
			else if (map[j][i] != '0' && map[j][i] != '1')
				exit_err("Error\n", NULL, "Map contains invalid arguments!");
		}
	}
	if (!req_com[EXIT_CNT] || !req_com[ITEM_CNT] || !req_com[START_POINT_CNT])
		exit_err("Error\n", NULL, "Map must contain at least one E, C, P!");
	free(req_com);
}


