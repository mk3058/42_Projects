/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:37 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/18 20:50:20 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(char *text, int *newline_index);

char	*get_next_line(int fd)
{
	static char	*text;
	char		*result;
	char		buff[BUFFER_SIZE + 1];
	int			newline_index;
	int			read_size;

	result = 0;
	read_size = BUFFER_SIZE;
	newline_index = 0;
	while (!find_newline(text, &newline_index) && read_size == BUFFER_SIZE)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		read_size = read(fd, buff, BUFFER_SIZE);
		text = ft_strjoin(text, buff);
	}
	if (ft_strlen(text) == 0)
	{
		free(text);
		return (0);
	}
	result = malloc(sizeof(char) * (newline_index + 1));
	ft_bzero(result, newline_index + 1);
	if (text[newline_index] == 0)
		ft_strlcat(result, text, newline_index + 1);
	else
		ft_strlcat(result, text, newline_index);
	ft_memmove(text, text + newline_index, ft_strlen(text) - newline_index);
	return (result);
}

static int	find_newline(char *text, int *newline_index)
{
	while (text && text[*newline_index])
	{
		if (text[*newline_index] == '\n')
		{
			*newline_index = *newline_index + 1;
			return (1);
		}
		*newline_index = *newline_index + 1;
	}
	return (0);
}
