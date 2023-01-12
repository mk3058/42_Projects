/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyu <minkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:53:42 by minkyuki          #+#    #+#             */
/*   Updated: 2023/01/12 12:59:21 by minkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= sign;
	return ((int)result);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	i = -1;
	result = malloc(size * count);
	if (result == 0)
		return (0);
	while (++i < size)
		((char *)result)[i] = 0;
	return (result);
}

int	argument_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", "Invalid Arguments");
		return (1);
	}
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!('0' <= argv[i][j] && argv[i][j] <= '9' || argv[i][j] == '+'))
			{
				printf("%s\n", "Invalid Arguments");
				return (1);
			}
		}
	}
	return (0);
}

void	print_timestamp(t_philo *p, int stat)
{
	int				diff;
	t_timeval		cur;
	char			*str[5];
	static int		flag;

	str[EATING] = "is eating";
	str[FORK] = "has taken a fork";
	str[SLEEPING] = "is sleeping";
	str[THINKING] = "is thinking";
	str[DEAD] = "\033[0;31mdied\033[0;30m";
	pthread_mutex_lock(&p->arg->print_mutex);
	if (flag)
	{
		pthread_mutex_unlock(&p->arg->print_mutex);
		return ;
	}
	gettimeofday(&cur, NULL);
	diff = time_diff(p->arg->start_time, cur);
	printf("%dms %d %s\n", diff, p->num + 1, str[stat]);
	if (stat == DEAD)
		flag = 1;
	pthread_mutex_unlock(&p->arg->print_mutex);
}

int	time_diff(t_timeval a, t_timeval b)
{
	return ((b.tv_sec - a.tv_sec) * 1000 + (b.tv_usec - a.tv_usec) / 1000);
}
