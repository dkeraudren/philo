/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:43:29 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 19:27:24 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo_main	*philo_main;

	if (argc < 5 || argc > 6)
		return (ft_error("Wrong number of arguments\n"));
	philo_main = malloc(sizeof(t_philo_main));
	if (!ft_init_all(philo_main, argc, argv))
		return (ft_error("Error during initialization\n"));
	if (!ft_create_threads(philo_main))
		return (ft_error("Error during thread creation\n"));
	if (!ft_join_threads(philo_main))
		return (ft_error("Error during thread joining\n"));
	free_philo(philo_main);
	return (0);
}
