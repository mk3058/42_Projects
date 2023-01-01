/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:42:38 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/01 20:58:50 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define VISITED 'V'

static int	*init_dfs(char **map, char **visited, int **direction);
static void	dfs(int **direction, char **visited, int x, int y);
static void	validation(char **visited);
static void	free_all(char **visited, int *player_loc, int **direction);

void	path_checker(char **map, int height)
{
	char	**visited;
	int		*player_loc;
	int		**direction;

	visited = ft_calloc(height + 1, sizeof(char *));
	direction = malloc(sizeof(int *) * 2);
	direction[0] = ft_calloc(4, sizeof(int));
	direction[1] = ft_calloc(4, sizeof(int));
	player_loc = init_dfs(map, visited, direction);
	dfs(direction, visited, player_loc[0], player_loc[1]);
	validation(visited);
	free_all(visited, player_loc, direction);
}

static void	dfs(int **direction, char **visited, int x, int y)
{
	int	i;
	int	nx;
	int	ny;

	i = -1;
	visited[x][y] = VISITED;
	while (++i < 4)
	{
		nx = x + direction[0][i];
		ny = y + direction[1][i];
		if ((nx >= 0 && ny >= 0) && visited[nx] && visited[nx][ny])
			if (visited[nx][ny] != '1' && visited[nx][ny] != VISITED)
				dfs(direction, visited, nx, ny);
	}
}

static void	validation(char **visited)
{
	int	i;

	while (*visited)
	{
		i = -1;
		while ((*visited)[++i])
		{
			if ((*visited)[i] == 'E' || (*visited)[i] == 'C')
				exit_err("Error\n", NULL, "Map dosen't have valid path!");
		}
		visited++;
	}
}

static int	*init_dfs(char **map, char **visited, int **direction)
{
	int	i;
	int	j;
	int	*player_loc;

	i = -1;
	player_loc = malloc(sizeof(int) * 2);
	while (map[++i])
	{
		j = -1;
		visited[i] = ft_strdup(map[i]);
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				player_loc[0] = i;
				player_loc[1] = j;
			}
		}
	}
	direction[0][0] = -1;
	direction[0][1] = 1;
	direction[1][2] = -1;
	direction[1][3] = 1;
	return (player_loc);
}

static void	free_all(char **visited, int *player_loc, int **direction)
{
	int	i;

	i = -1;
	while (visited[++i])
		free(visited[i]);
	free(visited);
	free(player_loc);
	free(direction[0]);
	free(direction[1]);
	free(direction);
}
