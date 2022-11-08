/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:07 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 19:29:34 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, t_size_t len)
{
	t_size_t	i;
	void	tmp[1];

	i = 0;
	ft_memcpy(tmp, src, len);
	while (i < len)
	{
		*(dst + i) = *(tmp + i);
	}
	return (dst);
}
