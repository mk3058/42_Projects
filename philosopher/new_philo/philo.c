/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:06:32 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/09 15:04:20 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*set_philo(int argc, char **argv, t_arg *arg);
static void		free_all(t_philo *philo, pthread_t *thread);

int	main(int argc, char **argv)
{
	int			cnt;
	t_philo		*philo;
	pthread_t	*thread;

	if (argument_check(argc, argv))
		return (1);
	philo = set_philo(argc, argv, malloc(sizeof(t_arg)));
	thread = malloc(sizeof(pthread_t) * philo->arg->number_of_philo + 1);
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo)
		if (pthread_create(thread + cnt, NULL, routine, (void *)(philo + cnt)))
			return (1);
	pthread_create(thread + cnt, NULL, monitor, (void *)philo);
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo + 1)
		pthread_join(thread[cnt], NULL);
	free_all(philo, thread);
}

static t_philo	*set_philo(int argc, char **argv, t_arg *arg)
{
	t_philo	*philo;
	int		*fork;
	int		i;

	i = -1;
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->must_eat = -1;
	pthread_mutex_init(&(arg->mutex), NULL);
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
		philo[i].stat = -1;
	}
	return (philo);
}

static void	free_all(t_philo *philo, pthread_t *thread)
{
	free(philo->fork);
	free(philo->arg);
	free(philo);
	free(thread);
}
