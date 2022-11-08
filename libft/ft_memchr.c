/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:57:13 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 19:29:36 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size_t n)
{
	t_size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
