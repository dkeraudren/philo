/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:14:53 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/22 22:43:47 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_done(t_philo_thread *philo)
{
	pthread_mutex_lock(&philo->rules->end_mutex);
	if (philo->rules->end)
	{
		pthread_mutex_unlock(&philo->rules->end_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->end_mutex);
	return (0);
}

int	check_done_eating(t_philo_main *philo_main)
{
	pthread_mutex_lock(&philo_main->done_eating_mutex);
	if (philo_main->done_eating == philo_main->rules->nb_philo)
	{
		pthread_mutex_unlock(&philo_main->done_eating_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo_main->done_eating_mutex);
	return (0);
}

void	*check(void *arg)
{
	int				i;
	t_philo_main	*philo_main;

	philo_main = (t_philo_main *)arg;
	i = 0;
	while (i < philo_main->rules->nb_philo)
	{
		pthread_mutex_lock(&philo_main->philo_threads[i].last_eat_mutex);
		if (ft_get_time() - philo_main->philo_threads[i].last_eat
			> philo_main->rules->time_to_die)
		{
			pthread_mutex_unlock(&philo_main->philo_threads[i].last_eat_mutex);
			ft_print_message(&philo_main->philo_threads[i], "died", DARK_RED);
			break ;
		}
		pthread_mutex_unlock(&philo_main->philo_threads[i].last_eat_mutex);
		if (check_done_eating(philo_main))
			break ;
		i = (i + 1) % philo_main->rules->nb_philo;
	}
	pthread_mutex_lock(&philo_main->rules->end_mutex);
	philo_main->rules->end = 1;
	pthread_mutex_unlock(&philo_main->rules->end_mutex);
	return (NULL);
}
