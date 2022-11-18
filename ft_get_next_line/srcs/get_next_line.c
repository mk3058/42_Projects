/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:37 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/18 17:06:33 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFF_SIZE 100

static int	find_newline(char *text, int *newline_index);

char	*get_next_line(int fd)
{
	static char	*text;
	char		*result;
	char		buff[BUFF_SIZE];
	int			newline_index;
	int			read_size;

	result = 0;
	read_size = BUFF_SIZE;
	newline_index = 0;
	while (!find_newline(text, &newline_index) && read_size == BUFF_SIZE)
	{
		ft_bzero(buff, BUFF_SIZE);
		read_size = read(fd, buff, BUFF_SIZE - 1);
		text = ft_strjoin(text, buff);
	}
	if (ft_strlen(text) == 0)
	{
		free(text);
		return (0);
	}
	result = malloc(sizeof(char) * newline_index);
	ft_bzero(result, newline_index);
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

int main()
{
	int fd = open("testfile", O_RDONLY);
	char *one_line;

	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == 0)
			break;
		printf("%s\n", one_line);
	}
	close(fd);
}