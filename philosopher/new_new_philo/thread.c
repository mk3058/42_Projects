/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:27:10 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 10:04:46 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *p);
static void	get_fork(t_philo *p, t_fork *f);
static void	put_fork(int philo_num, t_fork *f);
static int	pick_fork(int fork_num, t_fork *f);

void	*philo_routine(void *philo)
{
	t_philo			*p;

	p = philo;
	while (p->stat != ALIVE)
		;
	while (1)
	{
		if (p->stat == DEAD)
			return (NULL);
		if (eat(p) == DEAD)
			return (NULL);
		print_timestamp(p, SLEEPING);
		usleep(p->arg->time_to_sleep * 1000);
		print_timestamp(p, THINKING);
	}
}

static int	eat(t_philo *p)
{
	struct timeval	cur;

	get_fork(p, p->fork);
	gettimeofday(&cur, NULL);
	if (time_diff(p->last_eat, cur) >= p->arg->time_to_die)
	{
		p->stat = DEAD;
		print_timestamp(p, DEAD);
		put_fork(p->num, p->fork);
		return (DEAD);
	}
	print_timestamp(p, FORK);
	print_timestamp(p, EATING);
	usleep(p->arg->time_to_eat * 1000);
	put_fork(p->num, p->fork);
	(p->eat_cnt)++;
	gettimeofday(&p->last_eat, NULL);
	return (ALIVE);
}

static void	get_fork(t_philo *p, t_fork *f)
{
	if (p->num % 2)
	{
		while (pick_fork(p->num, f))
			;
		while (pick_fork((p->num + 1) % p->arg->number_of_philo, f))
			;
	}
	else
	{
		while (pick_fork((p->num + 1) % p->arg->number_of_philo, f))
			;
		while (pick_fork(p->num, f))
			;
	}
}

static int	pick_fork(int fork_num, t_fork *f)
{
	pthread_mutex_lock(&f[fork_num].mutex);
	if (f[fork_num].stat == OCCUPIED)
	{
		pthread_mutex_unlock(&f[fork_num].mutex);
		return (1);
	}
	else
		f[fork_num].stat = OCCUPIED;
	pthread_mutex_unlock(&f[fork_num].mutex);
	return (0);
}

static void	put_fork(int philo_num, t_fork *f)
{
	if (philo_num % 2)
	{
		pthread_mutex_lock(&f[philo_num].mutex);
		f[philo_num].stat = VACANT;
		pthread_mutex_unlock(&f[philo_num].mutex);
		pthread_mutex_lock(&f[(philo_num + 1) % 5].mutex);
		f[(philo_num + 1) % 5].stat = VACANT;
		pthread_mutex_unlock(&f[(philo_num + 1) % 5].mutex);
	}
	else
	{
		pthread_mutex_lock(&f[(philo_num + 1) % 5].mutex);
		f[(philo_num + 1) % 5].stat = VACANT;
		pthread_mutex_unlock(&f[(philo_num + 1) % 5].mutex);
		pthread_mutex_lock(&f[philo_num].mutex);
		f[philo_num].stat = VACANT;
		pthread_mutex_unlock(&f[philo_num].mutex);
	}
}
