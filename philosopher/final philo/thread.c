/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:40:06 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 12:59:35 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_life(t_philo *philo);
static int	eat(t_philo *philo);
static void	get_fork(t_philo *philo, pthread_mutex_t *fork);
static void	put_fork(t_philo *philo, pthread_mutex_t *fork);

void	*thread_routine(void *philo)
{
	while (((t_philo *)philo)->stat != ALIVE)
		;
	philo_life(philo);
	return (NULL);
}

static void	philo_life(t_philo *philo)
{
	while (philo->stat == ALIVE)
	{
		if (eat(philo) == DEAD)
			return ;
		print_timestamp(philo, SLEEPING);
		ft_usleep(philo->arg->time_to_sleep);
		if (is_dead(philo))
			return ;
		print_timestamp(philo, THINKING);
	}
}

static int	eat(t_philo *philo)
{
	get_fork(philo, philo->arg->fork);
	if (is_dead(philo))
	{
		put_fork(philo, philo->arg->fork);
		return (DEAD);
	}
	print_timestamp(philo, FORK);
	print_timestamp(philo, EATING);
	ft_usleep(philo->arg->time_to_eat);
	put_fork(philo, philo->arg->fork);
	(philo->eat_cnt)++;
	gettimeofday(&philo->last_eat, NULL);
	return (ALIVE);
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

static void	put_fork(t_philo *philo, pthread_mutex_t *fork)
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
