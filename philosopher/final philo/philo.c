/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:13:23 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 20:06:08 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*get_philo(int argc, char **argv);
static t_arg	*get_arg(int argc, char **argv);
static void		free_all(t_philo *philo, pthread_t *thread);

int	main(int argc, char **argv)
{
	t_philo		*philo;
	pthread_t	*thread;
	void		*res;
	int			i;

	i = -1;
	if (argument_check(argc, argv))
		return (1);
	philo = get_philo(argc, argv);
	if (!philo)
		return (1);
	thread = malloc(sizeof(pthread_t) * philo->arg->number_of_philo + 1);
	if (!thread)
		return (1);
	while (++i < philo->arg->number_of_philo)
		if (pthread_create(thread + i, NULL, thread_routine, philo + i))
			return (1);
	pthread_create(thread + i, NULL, philo_monitor, philo);
	i = -1;
	while (++i < philo->arg->number_of_philo + 1)
		pthread_join(thread[i], &res);
	if (res)
		printf("\033[0;32mPhilos are full!!\n");
	free_all(philo, thread);
}

static t_philo	*get_philo(int argc, char **argv)
{
	t_philo	*philo;
	t_arg	*arg;
	int		i;

	i = -1;
	arg = get_arg(argc, argv);
	if (!arg)
		return (NULL);
	philo = malloc(sizeof(t_philo) * arg->number_of_philo);
	if (!philo)
		return (NULL);
	while (++i < arg->number_of_philo)
	{
		philo[i].arg = arg;
		philo[i].num = i;
		philo[i].eat_cnt = 0;
		philo[i].stat = -1;
		pthread_mutex_init(&philo[i].last_eat_mutex, NULL);
	}
	return (philo);
}

static t_arg	*get_arg(int argc, char **argv)
{
	t_arg	*arg;
	int		i;

	i = -1;
	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->number_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat = ft_atoi(argv[5]);
	else
		arg->must_eat = -1;
	pthread_mutex_init(&arg->print_mutex, NULL);
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->number_of_philo);
	if (!arg->fork)
	{
		free(arg);
		return (NULL);
	}
	while (++i < arg->number_of_philo)
		pthread_mutex_init((arg->fork) + i, NULL);
	return (arg);
}

static void	free_all(t_philo *philo, pthread_t *thread)
{
	int	number_of_philo;
	int	i;

	number_of_philo = philo->arg->number_of_philo;
	i = -1;
	free(thread);
	pthread_mutex_destroy(&philo->arg->print_mutex);
	while (++i < number_of_philo)
	{
		pthread_mutex_destroy(&philo->arg->fork[i]);
		pthread_mutex_destroy(&philo[i].last_eat_mutex);
	}
	free(philo->arg->fork);
	free(philo->arg);
	free(philo);
}
