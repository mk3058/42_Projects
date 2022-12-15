/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:59:46 by minkyuki          #+#    #+#             */
/*   Updated: 2022/12/15 15:22:37 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**parse_envp(char **envp);
static void	free_all(char *cmd, char **env_path);
static char	*find_cmd_path(char	*cmd, char **envp);

void	execute_cmd(int argc, char **argv, char **envp, int cnt)
{
	char	*path;
	char	**arg;

	path = find_cmd_path(argv[cnt], envp);
	arg = ft_split(argv[cnt], ' ');
	free(arg[0]);
	arg[0] = ft_strdup(path);
	execve(path, arg, envp);
}

static char	*find_cmd_path(char	*cmd, char **envp)
{
	char	**env_path;
	char	*file_path;
	int		i;

	i = -1;
	env_path = parse_envp(envp);
	cmd = ft_strdup(cmd);
	if (ft_strchr(cmd, ' '))
		*(ft_strchr(cmd, ' ')) = '\0';
	while (env_path[++i])
	{
		file_path = ft_strjoin(env_path[i], cmd);
		if (access(file_path, R_OK | X_OK) == 0)
		{
			printf("%s\n", file_path);
			free_all(cmd, env_path);
			return (file_path);
		}
		else
			free(file_path);
	}
	free_all(cmd, env_path);
	exit_err("command not found", NULL, cmd);
	return (NULL);
}

static char	**parse_envp(char **envp)
{
	int		i;
	char	*tmp;
	char	**env_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	env_path = ft_split(envp[i] + 5, ':');
	i = -1;
	while (env_path[++i])
	{
		tmp = env_path[i];
		env_path[i] = ft_strjoin(env_path[i], "/");
		free(tmp);
	}
	return (env_path);
}

static void	free_all(char *cmd, char **env_path)
{
	int	size;

	size = 0;
	while (env_path[size])
		size++;
	dealloc(env_path, size);
	free(cmd);
}
