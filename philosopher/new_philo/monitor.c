/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:58:42 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/09 14:54:58 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philo_thread(t_philo *philo);

void	*monitor(void *philo)
{
	t_philo	*p;
	int		cnt;
	int		i;
	int		flag;

	p = philo;
	flag = 0;
	start_philo_thread(p);
	while (1)
	{
		i = -1;
		cnt = -1;
		while (!flag && ++i < p->arg->number_of_philo)
		{
			if (p[i].stat == DEAD)
				flag = 1;
			if (p[i].eat_cnt >= p->arg->must_eat)
				cnt++;
		}
		if (flag || cnt >= p->arg->number_of_philo)
		{
			change_philo_stat(p, DEAD, p->arg->number_of_philo);
			return (NULL);
		}
	}
}

static void	start_philo_thread(t_philo *philo)
{
	int				i;
	struct timeval	cur;

	i = -1;
	gettimeofday(&cur, NULL);
	while (++i < philo->arg->number_of_philo)
	{
		philo[i].start = cur;
		philo[i].last_eat = cur;
		philo[i].stat = ALIVE;
	}
}
