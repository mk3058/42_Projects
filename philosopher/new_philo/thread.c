/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:21:17 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/09 14:57:29 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	eat(t_philo *p);

void	change_philo_stat(t_philo *philo, int stat, int cnt)
{
	int			i;
	static int	flag;

	i = -1;
	pthread_mutex_lock(&philo->arg->mutex);
	while (++i < cnt)
		philo[i].stat = stat;
	if (flag)
		return ;
	if (stat == DEAD)
		flag = 1;
	print_timestamp(philo, stat);
	pthread_mutex_unlock(&philo->arg->mutex);
}

void	*routine(void *philo)
{
	t_philo			*p;
	struct timeval	cur;

	p = philo;
	while (p->stat == -1)
		;
	if ((p->num + 1) % 2 == 0)
		usleep(50);
	while (1)
	{
		if (p->stat == DEAD)
			return (NULL);
		while (eat(p))
		{
			gettimeofday(&cur, NULL);
			if (time_diff(p->last_eat, cur) > p->arg->time_to_die)
				change_philo_stat(p, DEAD, 1);
		}
		change_philo_stat(p, SLEEPING, 1);
		usleep(p->arg->time_to_sleep);
		change_philo_stat(p, THINKING, 1);
	}
}
//뭔가 이상한데? - 처음에 시간 검사 안하고 무조건 먹음, 먹는횟수 안들어왔을땐 처리 안됨, 조건 어떻게 들어올지 모르는데 usleep 써도 됨?

static int	eat(t_philo *p)
{
	pthread_mutex_lock(&p->arg->mutex);
	if (!p->fork[p->num] && !p->fork[p->num + 1])
	{
		p->fork[p->num] = 1;
		p->fork[p->num + 1] = 1;
		pthread_mutex_unlock(&p->arg->mutex);
		change_philo_stat(p, FORK, 1);
		change_philo_stat(p, EATING, 1);
		usleep(p->arg->time_to_eat);
		(p->eat_cnt)++;
		gettimeofday(&p->last_eat, NULL);
		pthread_mutex_lock(&p->arg->mutex);
		p->fork[p->num] = 0;
		p->fork[p->num + 1] = 0;
		pthread_mutex_unlock(&p->arg->mutex);
		return (0);
	}
	pthread_mutex_unlock(&p->arg->mutex);
	return (1);
}
