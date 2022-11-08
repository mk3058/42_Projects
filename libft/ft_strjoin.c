/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:48:18 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 21:11:28 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_size_t	tot_size;
	char		*result;

	tot_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)ft_calloc(tot_size, sizeof(char));
	ft_strlcat(result, s1, tot_size);
	ft_strlcat(result, s2, tot_size);
	return (result);
}