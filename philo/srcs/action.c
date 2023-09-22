/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:20 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/21 20:27:32 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_even(t_philo_thread *philo)
{
	pthread_mutex_lock(&philo->philo_main->forks[philo->forks[0]]);
	ft_print_message(philo, "has taken a fork", CYAN);
	if (philo->rules->nb_philo == 1)
	{
		usleep((philo->rules->time_to_die + 10) * 1000);
		pthread_mutex_unlock(&philo->philo_main->forks[philo->forks[0]]);
		return ;
	}
	pthread_mutex_lock(&philo->philo_main->forks[philo->forks[1]]);
	ft_print_message(philo, "has taken a fork", CYAN);
	ft_print_message(philo, "is eating", DARK_MAGENTA);
	philo->last_eat = ft_get_time();
	philo->nb_eat++;
	if (philo->philo_main->rules->nb_to_eat > 0
		&& philo->nb_eat == philo->philo_main->rules->nb_to_eat)
		philo->philo_main->done_eating += 1;
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->philo_main->forks[philo->forks[0]]);
	pthread_mutex_unlock(&philo->philo_main->forks[philo->forks[1]]);
}

void	ft_eat_odd(t_philo_thread *philo)
{
	pthread_mutex_lock(&philo->philo_main->forks[philo->forks[1]]);
	ft_print_message(philo, "has taken a fork", CYAN);
	pthread_mutex_lock(&philo->philo_main->forks[philo->forks[0]]);
	ft_print_message(philo, "has taken a fork", CYAN);
	ft_print_message(philo, "is eating", DARK_MAGENTA);
	philo->last_eat = ft_get_time();
	philo->nb_eat++;
	if (philo->philo_main->rules->nb_to_eat > 0
		&& philo->nb_eat == philo->philo_main->rules->nb_to_eat)
		philo->philo_main->done_eating += 1;
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->philo_main->forks[philo->forks[1]]);
	pthread_mutex_unlock(&philo->philo_main->forks[philo->forks[0]]);
}

void	ft_eat(t_philo_thread *philo)
{
	if (philo->id % 2 == 0)
		ft_eat_even(philo);
	else
		ft_eat_odd(philo);
}

void	ft_sleep(t_philo_thread *philo)
{
	ft_print_message(philo, "is sleeping", DARK_GREEN);
	usleep(philo->rules->time_to_sleep * 1000);
}

void	ft_think(t_philo_thread *philo)
{
	ft_print_message(philo, "is thinking", DARK_YELLOW);
	if (philo->rules->time_to_think > 0)
		usleep(philo->rules->time_to_think * 1000);
}
