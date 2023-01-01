/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:23 by minkyuki          #+#    #+#             */
/*   Updated: 2023/01/01 21:34:44 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define EXIT_CNT 0
#define ITEM_CNT 1
#define START_POINT_CNT 2

static int	get_map_height(char *map_path);
static void	map_checker(char **map);
static void	component_check(char **map);
static void	count_component(char **map, int *req_com);

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
	if (!map_height)
		exit_err("Error\n", NULL, "Map is empty!");
	map = ft_calloc(map_height + 1, sizeof(char *));
	while (i < map_height)
	{
		line = get_next_line(fd);
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map_checker(map);
	path_checker(map, map_height);
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
		if ((int)ft_strlen(map[i]) != map_width)
			exit_err("Error\n", NULL, "Map must be rectangular!");
		if (i == 0 || map[i + 1] == (char *) '\0')
		{
			while (map[i][++j])
				if (map[i][j] != '1')
					exit_err("Error\n", NULL, "Map must be closed by walls!");
		}
		else
			if (map[i][0] != '1' || map[i][map_width - 1] != '1')
				exit_err("Error\n", NULL, "Map must be closed by walls!");
	}
	component_check(map);
}

static void	component_check(char **map)
{
	int	*req_com;

	req_com = ft_calloc(3, sizeof(int));
	count_component(map, req_com);
	if (!req_com[START_POINT_CNT] || !req_com[EXIT_CNT] || !req_com[ITEM_CNT])
		exit_err("Error\n", NULL, "Map must contain at least one E, C, P!!");
	if (req_com[START_POINT_CNT] != 1)
		exit_err("Error\n", NULL, "Duplicates character P!");
	if (req_com[EXIT_CNT] != 1)
		exit_err("Error\n", NULL, "Duplicates character E!");
	free(req_com);
}

static void	count_component(char **map, int *req_com)
{
	int	i;
	int	j;

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
}
