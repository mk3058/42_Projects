/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:07 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/09 17:21:56 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		if (dst == 0 && src == 0)
			return (dst);
		len--;
		while (len >= 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

#include <stdio.h>
int main()
{
	char test[] = "test";

	printf("%s\n", ft_memmove(test + 1, test, 3));
}