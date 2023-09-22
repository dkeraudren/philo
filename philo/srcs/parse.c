/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:53:13 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/22 22:44:09 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_philo(t_philo_main *philo, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
		{
			ft_error("Arguments must be positive integers\n");
			free(philo->rules);
			free(philo);
			exit (0);
		}
		i++;
	}
	philo->rules->nb_philo = ft_atoi(argv[1]);
	philo->rules->time_to_die = ft_atoi(argv[2]);
	philo->rules->time_to_eat = ft_atoi(argv[3]);
	philo->rules->time_to_sleep = ft_atoi(argv[4]);
	philo->rules->nb_to_eat = -1;
	if (argc == 6)
		philo->rules->nb_to_eat = ft_atoi(argv[5]);
	philo->rules->end = 0;
	philo->rules->time_to_think = (philo->rules->time_to_die
			- philo->rules->time_to_eat - philo->rules->time_to_sleep) / 2;
	return (1);
}
