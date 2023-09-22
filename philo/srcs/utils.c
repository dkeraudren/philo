/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:16:46 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 20:14:08 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(100);
}

void	ft_print_message(t_philo_thread *philo, char *message, char *color)
{
	int	now;

	now = ft_get_time() - philo->rules->start_time;
	pthread_mutex_lock(&philo->philo_main->print);
	if (philo->philo_main->rules->end)
	{
		pthread_mutex_unlock(&philo->philo_main->print);
		return ;
	}
	printf("%s%d %d %s\033[0m\n", color,
		now, philo->id, message);
	pthread_mutex_unlock(&philo->philo_main->print);
}

int	ft_atoi(const char *nptr)
{
	int	index;
	int	retval;
	int	neg;

	index = 0;
	retval = 0;
	neg = 1;
	while (' ' == nptr[index] || '\f' == nptr[index] || '\n' == nptr[index]
		|| '\r' == nptr[index] || '\v' == nptr[index] || '\t' == nptr[index])
			index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			neg *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		retval = retval * 10 + ((nptr[index] - '0') * neg);
		index++;
	}
	return (retval);
}

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
