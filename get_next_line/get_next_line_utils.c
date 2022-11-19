/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:26:58 by minkyu            #+#    #+#             */
/*   Updated: 2022/11/19 23:13:35 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(t_list **lst, int fd)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp -> fd == fd)
			return (tmp);
		if (!tmp -> next)
			break ;
		tmp = tmp -> next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new -> fd = fd;
	new -> content = 0;
	new -> next = 0;
	if (*lst != 0)
		tmp -> next = new;
	else
		*lst = new;
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s[size])
		size++;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	if (!src)
		return (0);
	dst_length = (size_t)ft_strlen(dst);
	src_length = (size_t)ft_strlen(src);
	index = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (dst_length + index < dstsize - 1)
	{
		if (!src[index])
			break ;
		dst[dst_length + index] = src[index];
		index++;
	}
	dst[dst_length + index] = '\0';
	return (dst_length + src_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot_size;
	char	*result;

	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(sizeof(char) * tot_size);
	if (result == 0)
		return (0);
	ft_bzero(result, tot_size);
	ft_strlcat(result, s1, tot_size);
	ft_strlcat(result, s2, tot_size);
	free((void *)s1);
	return (result);
}
