/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:13:18 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/12 19:28:03 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define EATING 0
# define FORK 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define ALIVE 5

typedef struct timeval	t_timeval;

typedef struct s_arg
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	t_timeval		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*fork;
}	t_arg;

typedef struct s_philo
{
	int				num;
	int				eat_cnt;
	int				stat;
	t_timeval		last_eat;
	pthread_mutex_t	last_eat_mutex;
	t_arg			*arg;
}	t_philo;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		argument_check(int argc, char **argv);
int		time_diff(t_timeval a, t_timeval b);
void	print_timestamp(t_philo *p, int stat);
void	*thread_routine(void *philo);
void	*philo_monitor(void *philo);
void	ft_usleep(int ms);
int		is_dead(t_philo *philo);
void	put_fork(t_philo *philo, pthread_mutex_t *fork);

#endif