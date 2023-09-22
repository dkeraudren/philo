/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:24:17 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/18 19:56:01 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_philo_main *philo_main)
{
	int	i;

	i = 0;
	while (i < philo_main->rules->nb_philo)
	{
		if (pthread_create(&philo_main->philo_threads[i].thread, NULL,
				&routine, &philo_main->philo_threads[i]))
			return (0);
		i++;
	}
	philo_main->rules->start_time = ft_get_time();
	pthread_mutex_unlock(&philo_main->print);
	if (pthread_create(&philo_main->check_thread, NULL, &check, philo_main))
		return (0);
	return (1);
}

int	ft_join_threads(t_philo_main *philo_main)
{
	int	i;

	i = 0;
	while (i < philo_main->rules->nb_philo)
	{
		if (pthread_join(philo_main->philo_threads[i].thread, NULL))
			return (0);
		i++;
	}
	if (pthread_join(philo_main->check_thread, NULL))
		return (0);
	return (1);
}
