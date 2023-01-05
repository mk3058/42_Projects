/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:50 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/05 20:43:10 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		set_arguments(int argc, char **argv, t_arg **arg);
void	*philo_f(void *mutex);
void	init_philo(t_arg *arg, t_philo *philo, int cnt);

int	main(int argc, char **argv)
{
	int				cnt;
	t_philo			*philo;
	t_arg			*arg;
	pthread_t		*thread;

	cnt = -1;
	if (set_arguments(argc, argv, &arg))
		return (1);
	philo = malloc(sizeof(t_philo) * arg->number_of_philo);
	thread = malloc(sizeof(pthread_t) * arg->number_of_philo);
	pthread_mutex_init(&(arg -> mutex), NULL);
	while (++cnt < arg->number_of_philo)
	{
		init_philo(arg, philo, cnt);
		if (pthread_create(&thread[cnt], NULL, philo_f, (void *)(philo + cnt)))
			return (1);
	}
	cnt = -1;
	while (++cnt < arg -> number_of_philo)
		pthread_join(thread[cnt], NULL);
}

void	*philo_f(void *philo)
{
	pthread_mutex_lock(&((t_philo *)philo)->arg->mutex);
	printf("philo num : %d\n", ((t_philo *)philo) -> num);
	printf("eat cnt : %d\n", ((t_philo *)philo)->eat_cnt);
	printf("stat : %d\n", ((t_philo *)philo) -> stat);
	printf("last eat : %ld . %ld\n", ((t_philo *)philo) -> last_eat.tv_sec, ((t_philo *)philo) -> last_eat.tv_usec);
	pthread_mutex_unlock(&((t_philo *)philo)->arg->mutex);
}

void	init_philo(t_arg *arg, t_philo *philo, int cnt)
{
	philo[cnt].num = cnt;
	philo[cnt].eat_cnt = 0;
	philo[cnt].stat = THINKING;
	gettimeofday(&philo[cnt].last_eat, NULL);
	philo[cnt].arg = arg;
}

int	set_arguments(int argc, char **argv, t_arg **arg)
{
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Invalid Arguments");
		return (-1);
	}
	(*arg) = malloc(sizeof(t_arg));
	(*arg)->number_of_philo = ft_atoi(argv[1]);
	(*arg)->time_to_die = ft_atoi(argv[2]);
	(*arg)->time_to_eat = ft_atoi(argv[3]);
	(*arg)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*arg)->must_eat = ft_atoi(argv[5]);
	else
		(*arg)->must_eat = -1;
	return (0);
}
