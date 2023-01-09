/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:43:00 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/09 13:50:11 by minkyu           ###   ########.fr       */
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

typedef struct s_arg
{
	int				number_of_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				must_eat;
	pthread_mutex_t	mutex;
}	t_arg;

typedef struct s_philo
{
	int				num;
	int				eat_cnt;
	int				stat;
	int				*fork;
	struct s_arg	*arg;
	struct timeval	start;
	struct timeval	last_eat;
}	t_philo;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		argument_check(int argc, char **argv);
int		time_diff(struct timeval a, struct timeval b);
void	print_timestamp(t_philo *p, int stat);
void	change_philo_stat(t_philo *philo, int stat, int cnt);
void	*routine(void *philo);
void	*monitor(void *philo);

#endif