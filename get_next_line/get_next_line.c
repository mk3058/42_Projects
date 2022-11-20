/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:22:52 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/20 11:41:32 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *content, int rd_size);
static void	*ft_memcpy(void *dst, const void *src, size_t n);
static void	ft_lstdelone(t_list **file_list, t_list *lst);

char	*get_next_line(int fd)
{
	static t_list	*file_list;
	t_list			*cur_file;
	char			buf[BUFFER_SIZE + 1];
	char			*line;
	int				rd_size;

	cur_file = get_list(&file_list, fd);
	rd_size = BUFFER_SIZE;
	line = cur_file -> content;
	while (line == cur_file -> content)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		rd_size = read(fd, buf, BUFFER_SIZE);
		if ((rd_size == 0 && !ft_strlen(cur_file -> content)) || rd_size < 0)
		{
			ft_lstdelone(&file_list, cur_file);
			return (NULL);
		}
		cur_file -> content = ft_strjoin(cur_file -> content, buf);
		line = get_line(cur_file -> content, rd_size);
	}
	return (line);
}

static char	*get_line(char *content, int rd_size)
{
	int		i;
	int		line_size;
	char	*line;

	i = -1;
	line_size = 0;
	while (content[++i])
	{
		if (content[i] == '\n')
		{
			line_size = (i + 1);
			break ;
		}
	}
	if (!line_size && rd_size < BUFFER_SIZE)
		line_size = i;
	else if (!line_size && rd_size == BUFFER_SIZE)
		return (content);
	line = malloc(sizeof(char) * line_size + 1);
	if (line == 0)
		return (NULL);
	ft_bzero(line, line_size + 1);
	ft_strlcat(line, content, line_size + 1);
	ft_memcpy(content, content + line_size, ft_strlen(content + line_size) + 1);
	return (line);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static void	ft_lstdelone(t_list **file_list, t_list *lst)
{
	t_list	*pre;

	if (!lst || !(*file_list))
		return ;
	pre = 0;
	while ((*file_list)-> fd != lst -> fd)
	{
		pre = *file_list;
		*file_list = (*file_list)-> next;
	}
	if (pre)
		pre -> next = lst -> next;
	else
		*file_list = 0;
	free(lst -> content);
	free(lst);
}
