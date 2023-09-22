/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:37:04 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/22 22:31:50 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define CYAN "\033[96m"
# define DARK_YELLOW "\033[33m"
# define DARK_GREEN "\033[32m"
# define DARK_RED "\033[31m"
# define DARK_MAGENTA "\033[35m"
# define RESET "\033[0m"

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				nb_to_eat;
	int				start_time;
	int				end;
	pthread_mutex_t	end_mutex;
}	t_rules;

// declare t_philo main to use it in t_philo_thread
typedef struct s_philo_main	t_philo_main;

typedef struct s_philo_thread
{
	int				id;
	int				nb_eat;
	int				last_eat;
	int				dead;
	int				forks[2];
	pthread_t		thread;
	t_rules			*rules;
	t_philo_main	*philo_main;
	pthread_mutex_t	last_eat_mutex;
}	t_philo_thread;

typedef struct s_philo_main
{
	t_rules			*rules;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	done_eating_mutex;
	t_philo_thread	*philo_threads;
	pthread_t		check_thread;
	int				done_eating;
}	t_philo_main;

// utils.c
int		ft_atoi(const char *nptr);
int		ft_error(char *str);
int		ft_get_time(void);
void	ft_print_message(t_philo_thread *philo, char *message, char *color);

// thread.c
int		ft_create_threads(t_philo_main *philo_main);
int		ft_join_threads(t_philo_main *philo_main);

// routine.c
void	*routine(void *arg);

// parse.c
int		parse_philo(t_philo_main *philo_main, int argc, char **argv);

// inits.c
int		ft_init_all(t_philo_main *philo_main, int argc, char **argv);

// ft_isint.c
int		ft_isint(const char *str);

// free.c
void	free_philo(t_philo_main *philo);

// check.c
void	*check(void *arg);
int		check_done(t_philo_thread *philo);

// action.c
void	ft_eat(t_philo_thread *philo);
void	ft_think(t_philo_thread *philo);
void	ft_sleep(t_philo_thread *philo);

#endif