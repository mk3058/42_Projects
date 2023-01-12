/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:58:55 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 13:00:31 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int ms)
{
	t_timeval	start_time;
	t_timeval	cur_time;

	gettimeofday(&start_time, NULL);
	gettimeofday(&cur_time, NULL);
	while (time_diff(start_time, cur_time) <= ms)
	{
		usleep(100);
		gettimeofday(&cur_time, NULL);
	}
}

int	is_dead(t_philo *philo)
{
	t_timeval	cur;

	gettimeofday(&cur, NULL);
	if (time_diff(philo->last_eat, cur) >= philo->arg->time_to_die)
	{
		philo->stat = DEAD;
		print_timestamp(philo, DEAD);
		return (1);
	}
	return (0);
}
