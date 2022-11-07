/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:26:25 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/07 16:05:00 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	res;
	unsigned int	index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (index >= n)
			break ;
		res = s1[index] - s2[index];
		if (res != 0)
			return ((int)res);
		index++;
	}
	return (0);
}
