/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:50 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/09 13:59:54 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*set_philo(int argc, char **argv);
void	*routine(void *philo);
void	print_timestamp(t_philo *p, int stat);
void	*routine(void *philo);
int		eat(t_philo *p);
void	free_all(t_philo *philo, pthread_t *thread);
int		time_diff(struct timeval a, struct timeval b);

int	main(int argc, char **argv)
{
	int				cnt;
	t_philo			*philo;
	pthread_t		*thread;

	cnt = -1;
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Invalid Arguments");
		return (1);
	}
	philo = set_philo(argc, argv);
	thread = malloc(sizeof(pthread_t) * philo->arg->number_of_philo + 1);
	pthread_mutex_init(&(philo->arg->mutex), NULL);
	while (++cnt < philo->arg->number_of_philo)
	{
		if (pthread_create(&thread[cnt], NULL, routine, (void *)(philo + cnt)))
			return (1);
	}
	pthread_create(&thread[cnt], NULL, monitor, (void *)philo);
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo + 1)
		pthread_join(thread[cnt], NULL);
	free_all(philo, thread);
}

void	free_all(t_philo *philo, pthread_t *thread)
{
	free(philo->fork);
	free(philo->arg);
	free(philo);
	free(thread);
}

void	*routine(void *philo)
{
	t_philo			*p;
	struct timeval	cur;

	p = philo;
	if ((p->num + 1) % 2 == 0)
		usleep(50);
	gettimeofday(&p->start, NULL);
	gettimeofday(&p->last_eat, NULL);
	while (1)
	{
		if (p->stat == DEAD)
			return (NULL);
		while (eat(p))
		{
			if (p->stat == DEAD)
			return (NULL);
			gettimeofday(&cur, NULL);
			if (time_diff(p->last_eat, cur) > p->arg->time_to_die)
			{
				print_timestamp(p, DEAD);
				pthread_mutex_lock(&p->arg->mutex);
				p->stat = DEAD;
				pthread_mutex_unlock(&p->arg->mutex);
			}
			return (NULL);
		}
		if (p->stat == DEAD)
			return (NULL);
		print_timestamp(p, SLEEPING);
		usleep(p->arg->time_to_sleep);
		print_timestamp(p, THINKING);
		usleep(200);
	}
}

int	eat(t_philo *p)
{
	pthread_mutex_lock(&p->arg->mutex);
	if (!p->fork[p->num] && !p->fork[p->num + 1])
	{
		p->fork[p->num] = 1;
		p->fork[p->num + 1] = 1;
		print_timestamp(p, FORK);
		pthread_mutex_unlock(&p->arg->mutex);
		usleep(p->arg->time_to_eat);
		(p->eat_cnt)++;
		gettimeofday(&p->last_eat, NULL);
		print_timestamp(p, EATING);
		p->fork[p->num] = 0;
		p->fork[p->num + 1] = 0;
		return (0);
	}
	pthread_mutex_unlock(&p->arg->mutex);
	return (1);
}

void	print_timestamp(t_philo *p, int stat)
{
	suseconds_t		diff;
	struct timeval	cur;
	char			*str[5];

	str[EATING] = "is eating";
	str[FORK] = "has taken a fork";
	str[SLEEPING] = "is sleeping";
	str[THINKING] = "is thinking";
	str[DEAD] = "died";
	if (stat == EATING)
		diff = time_diff(p->start, p->last_eat);
	else
	{
		gettimeofday(&cur, NULL);
		diff = time_diff(p->start, cur);
	}
	if (p->stat != DEAD)
		printf("%dms %d %s\n", diff, p->num + 1, str[stat]);
}

int	time_diff(struct timeval a, struct timeval b)
{
	return (((b.tv_sec - a.tv_sec) * 1000) + b.tv_usec - a.tv_usec);
}

t_philo	*set_philo(int argc, char **argv)
{
	t_philo	*philo;
	t_arg	*arg;
	int		*fork;
	int		i;

	i = -1;
	arg = malloc(sizeof(t_arg));
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->must_eat = -1;
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	fork = ft_calloc(arg->number_of_philo, sizeof(int));
	philo = malloc(sizeof(t_philo) * arg->number_of_philo);
	while (++i < arg->number_of_philo)
	{
		philo[i].arg = arg;
		philo[i].fork = fork;
		philo[i].num = i;
		philo[i].eat_cnt = 0;
		philo[i].stat = ALIVE;
	}
	return (philo);
}
