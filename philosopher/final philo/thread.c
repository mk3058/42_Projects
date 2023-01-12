/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:40:06 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 14:43:09 by minkyu           ###   ########.fr       */
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
	if (philo->num % 2)
		ft_usleep(philo->arg->time_to_eat / 2);
	while (philo->stat == ALIVE)
	{
		eat(philo);
		print_timestamp(philo, SLEEPING);
		ft_usleep(philo->arg->time_to_sleep);
		if (is_dead(philo))
			return ;
		print_timestamp(philo, THINKING);
		ft_usleep(5);
	}
}

static void	eat(t_philo *philo)
{
	get_fork(philo, philo->arg->fork);
	print_timestamp(philo, FORK);
	print_timestamp(philo, EATING);
	gettimeofday(&philo->last_eat, NULL);
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
