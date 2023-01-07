/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:53:42 by minkyuki          #+#    #+#             */
/*   Updated: 2023/01/07 14:59:54 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return ((int)result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	int		i;

	i = -1;
	result = malloc(size * count);
	if (result == 0)
		return (0);
	while (++i < size)
		((char *)result)[i] = 0;
	return (result);
}
