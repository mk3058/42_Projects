/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:16:22 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 12:49:14 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*check_stat(t_philo *philo, int cnt_flag);
static void	kill_all_philo(t_philo *philo);

void	*philo_monitor(void *philo)
{
	t_timeval	start_time;
	int			i;

	i = -1;
	gettimeofday(&start_time, NULL);
	((t_philo *)philo)->arg->start_time = start_time;
	while (++i < ((t_philo *)philo)->arg->number_of_philo)
	{
		((t_philo *)philo)[i].last_eat = start_time;
		((t_philo *)philo)[i].stat = ALIVE;
	}
	return (check_stat(philo, (((t_philo *)philo)->arg->must_eat > -1)));
}

static void	*check_stat(t_philo *philo, int cnt_flag)
{
	int	i;
	int	cnt;
	
	while (1)
	{
		i = -1;
		cnt = 0;
		while (++i < philo->arg->number_of_philo)
		{
			if (philo[i].stat == DEAD)
			{
				kill_all_philo(philo);
				return (NULL);
			}
			if (cnt_flag && philo[i].eat_cnt >= philo->arg->must_eat)
				cnt++;
		}
		if (cnt_flag && cnt >= philo->arg->number_of_philo)
		{
			kill_all_philo(philo);
			return (philo);
		}
	}
	return (NULL);
}

static void	kill_all_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arg->number_of_philo)
		philo[i].stat = DEAD;
}