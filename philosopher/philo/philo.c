/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:50 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/07 15:11:22 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*set_philo(int argc, char **argv);
void	*routine(void *philo);

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
	thread = malloc(sizeof(pthread_t) * philo->arg->number_of_philo);
	pthread_mutex_init(&(philo->arg->mutex), NULL);
	while (++cnt < philo->arg->number_of_philo)
	{
		gettimeofday(&philo[cnt].last_eat, NULL);
		if (pthread_create(&thread[cnt], NULL, routine, (void *)(philo + cnt)))
			return (1);
	}
	cnt = -1;
	while (++cnt < philo->arg->number_of_philo)
		pthread_join(thread[cnt], NULL);
}

void	*routine(void *philo)
{
	
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
		philo[i].stat = THINKING;
	}
	return (philo);
}
