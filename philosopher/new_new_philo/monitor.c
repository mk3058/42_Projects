/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:03:16 by minkyuki          #+#    #+#             */
/*   Updated: 2023/01/11 19:49:56 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_stat(t_philo *p);

void	*philo_monitor(void *philo)
{
	int				i;
	t_philo			*p;
	struct timeval	cur;

	i = -1;
	p = philo;
	gettimeofday(&cur, NULL);
	p->arg->start_time = cur;
	while (++i < p->arg->number_of_philo)
	{
		p[i].stat = ALIVE;
		p[i].last_eat = cur;
	}
	while (check_stat(p))
		usleep(100);
	return (NULL);
}

static int	check_stat(t_philo *p)
{
	int	i;
	int	cnt;
	int	flag;

	i = -1;
	cnt = 0;
	flag = 0;
	while (++i < p->arg->number_of_philo)
	{
		if (p[i].stat == DEAD)
		{
			flag = 1;
			break ;
		}
		if (p[i].eat_cnt >= p->arg->must_eat)
			cnt++;
	}
	if (flag || (p->arg->must_eat >= 0 && cnt >= p->arg->number_of_philo))
	{
		i = -1;
		while (++i < p->arg->number_of_philo)
			p[i].stat = DEAD;
		return (0);
	}
	return (1);
}
