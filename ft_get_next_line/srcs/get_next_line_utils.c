/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:33 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/18 15:13:58 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst == 0 && src == 0)
		return (dst);
	while (++i < n)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
    ((unsigned char *)dst)[i] = '\0';
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char *)s)[i] = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (s != 0)
		while (s[size])
			size++;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	index;

	if (src == 0)
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
	return (result);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == 0 && src == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}	
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
