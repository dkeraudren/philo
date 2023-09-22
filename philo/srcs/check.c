/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:14:53 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 20:27:49 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_done(t_philo_thread *philo)
{
	if (philo->rules->end)
		return (1);
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
		if (ft_get_time() - philo_main->philo_threads[i].last_eat
			> philo_main->rules->time_to_die)
		{
			ft_print_message(&philo_main->philo_threads[i], "died", DARK_RED);
			break ;
		}
		if (philo_main->done_eating == philo_main->rules->nb_philo)
			break ;
		i = (i + 1) % philo_main->rules->nb_philo;
	}
	philo_main->rules->end = 1;
	return (NULL);
}
