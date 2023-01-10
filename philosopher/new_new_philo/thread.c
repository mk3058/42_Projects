/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:27:10 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/10 23:59:26 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo	*p;

	p = philo;
	while (p->stat != ALIVE)
		;
	
}

static void	get_fork(int philo_num, t_fork *f)
{
	if (philo_num % 2)
	{
		pthread_mutex_lock(&f[philo_num].mutex);
		while (f[philo_num].stat == OCCUPIED)
			;
		f[philo_num].stat == OCCUPIED;
		pthread_mutex_unlock(&f[philo_num].mutex);
	}
	pthread_mutex_lock(&f[(philo_num + 1) % 5].mutex);
	while (f[(philo_num + 1) % 5].stat == OCCUPIED)
		;
	f[(philo_num + 1) % 5].stat == OCCUPIED;
	pthread_mutex_unlock(&f[(philo_num + 1) % 5].mutex);
	if (!(philo_num % 2))
	{
		pthread_mutex_lock(&f[philo_num].mutex);
		while (f[philo_num].stat == OCCUPIED)
			;
		f[philo_num].stat == OCCUPIED;
		pthread_mutex_unlock(&f[philo_num].mutex);
	}
}

static void	put_fork(int philo_num, t_fork *f)
{
	if (philo_num % 2)
	{
		pthread_mutex_lock(&f[(philo_num + 1) % 5].mutex);
		f[(philo_num + 1) % 5].stat == VACANT;
		pthread_mutex_unlock(&f[(philo_num + 1) % 5].mutex);
		pthread_mutex_lock(&f[philo_num].mutex);
		f[philo_num].stat == VACANT;
		pthread_mutex_unlock(&f[philo_num].mutex);
	}
	else
	{
		pthread_mutex_lock(&f[philo_num].mutex);
		f[philo_num].stat == VACANT;
		pthread_mutex_unlock(&f[philo_num].mutex);
		pthread_mutex_lock(&f[(philo_num + 1) % 5].mutex);
		f[(philo_num + 1) % 5].stat == VACANT;
		pthread_mutex_unlock(&f[(philo_num + 1) % 5].mutex);
	}
}
