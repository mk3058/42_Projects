/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:11:56 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 19:18:10 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		size;
	int		index;

	index = 0;
	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	while (index < size)
	{
		dest[index] = s1[index];
		index++;
	}
	dest[size] = '\0';
	return (dest);
}
