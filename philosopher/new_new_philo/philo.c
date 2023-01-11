/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:48:46 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/11 16:27:52 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*set_philo(t_arg *a);
static t_arg	*get_arg(int argc, char **argv);
static void		free_all(t_philo *philo, pthread_t *thread);

int	main(int argc, char **argv)
{
	int			cnt;
	t_philo		*philo;
	pthread_t	*thread;

	if (argument_check(argc, argv))
		return (1);
	philo = set_philo(get_arg(argc, argv));
	thread = malloc(sizeof(pthread_t) * philo->arg->number_of_philo + 1);
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo)
		if (pthread_create(thread + cnt, NULL, philo_routine, philo + cnt))
			return (1);
	pthread_create(thread + cnt, NULL, philo_monitor, philo);
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo + 1)
	{
		//printf("====%d\n", cnt); //////////////////////////////////////////////////////////
		pthread_join(thread[cnt], NULL);
	}
	free_all(philo, thread);
}

static t_philo	*set_philo(t_arg *a)
{
	t_philo	*p;
	t_fork	*f;
	int		i;

	i = -1;
	p = malloc(sizeof(t_philo) * a->number_of_philo);
	f = malloc(sizeof(t_fork) * a->number_of_philo);
	while (++i < a->number_of_philo)
	{
		p[i].arg = a;
		p[i].fork = f;
		p[i].num = i;
		p[i].eat_cnt = 0;
		p[i].stat = -1;
		f[i].stat = VACANT;
		pthread_mutex_init(&(f[i].mutex), NULL);
	}
	return (p);
}

static t_arg	*get_arg(int argc, char **argv)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	else
		arg->must_eat = -1;
	return (arg);
}

static void	free_all(t_philo *philo, pthread_t *thread)
{
	int		i;
	int		number_of_philo;

	i = -1;
	number_of_philo = philo->arg->number_of_philo;
	free(thread);
	free(philo->arg);
	while (++i < number_of_philo)
		pthread_mutex_destroy(&(philo->fork[i].mutex));
	free(philo->fork);
	free(philo);
}
