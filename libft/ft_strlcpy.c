/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:40:21 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 19:29:22 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcpy(char *dest, const char *src, t_size_t size)
{
	unsigned int	index;

	index = 0;
	while (index + 1 < size)
	{
		if (src[index] == '\0')
			break ;
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return ((t_size_t)ft_strlen(src));
}
