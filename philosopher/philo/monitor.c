/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:26:15 by minkyuki          #+#    #+#             */
/*   Updated: 2023/01/08 13:44:52 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *philo)
{
	int	i;
	int	cnt;
	int	flag;
	t_philo *p;

	p = philo;
	flag = -1;
	while (1)
	{
		i = -1;
		cnt = 0;
		while (flag == -1 && ++i < p->arg->number_of_philo)
		{
			if (p[i].stat == DEAD)
				flag = i;
			if (p[i].eat_cnt >= p->arg->must_eat)
				cnt++;
		}
		if (flag != -1 || cnt >= p->arg->number_of_philo)
		{
			i = -1;
			while (++i < p->arg->number_of_philo)
				p[i].stat = DEAD;
			return (NULL);
		}
	}
}
