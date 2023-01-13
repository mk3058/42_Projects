/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:40:06 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/13 12:14:32 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_life(t_philo *philo);
static void	eat(t_philo *philo);
static void	get_fork(t_philo *philo, pthread_mutex_t *fork);

void	*thread_routine(void *philo)
{
	while (((t_philo *)philo)->stat != ALIVE)
		;
	if (((t_philo *)philo)->arg->number_of_philo == 1)
	{
		while (!is_dead(philo))
			;
		return (NULL);
	}
	philo_life(philo);
	return (NULL);
}

static void	philo_life(t_philo *philo)
{
	t_timeval	cur;
	int			remain;

	if (philo->num % 2)
		ft_usleep(philo->arg->time_to_eat / 2);
	while (philo->stat == ALIVE)
	{
		eat(philo);
		print_timestamp(philo, SLEEPING);
		ft_usleep(philo->arg->time_to_sleep);
		print_timestamp(philo, THINKING);
		if (philo->arg->number_of_philo % 2)
		{
			gettimeofday(&cur, NULL);
			remain = philo->arg->time_to_die - time_diff(philo->last_eat, cur);
			ft_usleep(remain / 2);
		}
	}
}

static void	eat(t_philo *philo)
{
	get_fork(philo, philo->arg->fork);
	print_timestamp(philo, FORK);
	print_timestamp(philo, EATING);
	pthread_mutex_lock(&philo->last_eat_mutex);
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(&philo->last_eat_mutex);
	ft_usleep(philo->arg->time_to_eat);
	put_fork(philo, philo->arg->fork);
	(philo->eat_cnt)++;
}

static void	get_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	tot_philo_num;

	tot_philo_num = philo->arg->number_of_philo;
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(&fork[philo->num]);
		pthread_mutex_lock(&fork[(philo->num + 1) % tot_philo_num]);
	}
	else
	{
		pthread_mutex_lock(&fork[(philo->num + 1) % tot_philo_num]);
		pthread_mutex_lock(&fork[philo->num]);
	}
}

void	put_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	tot_philo_num;

	tot_philo_num = philo->arg->number_of_philo;
	if (philo->num % 2 == 0)
	{
		pthread_mutex_unlock(&fork[philo->num]);
		pthread_mutex_unlock(&fork[(philo->num + 1) % tot_philo_num]);
	}
	else
	{
		pthread_mutex_unlock(&fork[(philo->num + 1) % tot_philo_num]);
		pthread_mutex_unlock(&fork[philo->num]);
	}
}
