/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:36:28 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 19:36:52 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo_thread	*philo;

	philo = (t_philo_thread *)arg;
	philo->last_eat = philo->philo_main->rules->start_time;
	pthread_mutex_lock(&philo->philo_main->print);
	pthread_mutex_unlock(&philo->philo_main->print);
	while (!check_done(philo))
	{
		ft_eat(philo);
		if (philo->rules->nb_philo == 1)
			break ;
		if (check_done(philo))
			break ;
		ft_think(philo);
		if (check_done(philo))
			break ;
		ft_sleep(philo);
	}
	return (NULL);
}
