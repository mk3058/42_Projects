/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:22:55 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 21:11:30 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcat(char *dst, const char *src, t_size_t dstsize)
{
	t_size_t	dst_length;
	t_size_t	src_length;
	t_size_t	index;

	dst_length = (t_size_t)ft_strlen(dst);
	src_length = (t_size_t)ft_strlen(src);
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
