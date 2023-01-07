/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:43:00 by minkyu            #+#    #+#             */
/*   Updated: 2023/01/07 14:59:05 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define EATING 1
# define THINKING 2
# define SLEEPING 3

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
	struct timeval	last_eat;
}	t_philo;

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif