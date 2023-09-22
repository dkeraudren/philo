/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:52:02 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 20:09:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_forks(t_philo_main *philo_main)
{
	int	i;

	i = 0;
	philo_main->forks = malloc(sizeof(pthread_mutex_t)
			* philo_main->rules->nb_philo);
	if (!philo_main->forks)
		return (0);
	while (i < philo_main->rules->nb_philo)
	{
		if (pthread_mutex_init(&philo_main->forks[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&philo_main->print, NULL))
		return (0);
	pthread_mutex_lock(&philo_main->print);
	return (1);
}

int	ft_init_threads(t_philo_main *philo_main)
{
	int	i;

	i = 0;
	philo_main->philo_threads = malloc(sizeof(t_philo_thread)
			* philo_main->rules->nb_philo);
	if (!philo_main->philo_threads)
		return (0);
	while (i < philo_main->rules->nb_philo)
	{
		philo_main->philo_threads[i].id = i;
		philo_main->philo_threads[i].nb_eat = 0;
		philo_main->philo_threads[i].dead = 0;
		philo_main->philo_threads[i].forks[0] = i;
		philo_main->philo_threads[i].forks[1] = (i + 1)
			% philo_main->rules->nb_philo;
		philo_main->philo_threads[i].rules = philo_main->rules;
		philo_main->philo_threads[i].philo_main = philo_main;
		philo_main->philo_threads[i].last_eat = ft_get_time();
		i++;
	}
	return (1);
}

int	ft_init_all(t_philo_main *philo_main, int argc, char **argv)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (0);
	philo_main->rules = rules;
	philo_main->done_eating = 0;
	parse_philo(philo_main, argc, argv);
	if (!ft_init_forks(philo_main))
		return (0);
	if (!ft_init_threads(philo_main))
		return (0);
	return (1);
}
