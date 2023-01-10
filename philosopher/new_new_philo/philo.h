/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:48:55 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/10 23:49:40 by minkyu           ###   ########.fr       */
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

# define VACANT	0
# define OCCUPIED 1

typedef struct s_arg
{
	int				number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				must_eat;
	struct timeval	start_time;
}	t_arg;

typedef struct s_philo
{
	int				num;
	int				eat_cnt;
	int				stat;
	struct s_arg	*arg;
	struct s_fork	*fork;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_fork
{
	int				stat;
	pthread_mutex_t	mutex;
}	t_fork;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		argument_check(int argc, char **argv);
void	*philo_routine(void *philo);
void	print_timestamp(t_philo *p, int stat);
int		time_diff(struct timeval a, struct timeval b);

#endif