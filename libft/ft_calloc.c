/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:48:22 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/08 19:29:37 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(t_size_t count, t_size_t size)
{
	void	*result;

	result = malloc(size * count);
	ft_bzero(result, size * count);
	return (result);
}
