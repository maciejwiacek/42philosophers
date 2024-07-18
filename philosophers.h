/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:43 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 21:32:16 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_PHILOS 200

typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	bool			eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	bool			*dead;
	t_mtx			*r_fork;
	t_mtx			*l_fork;
	t_mtx			*write_lock;
	t_mtx			*dead_lock;
	t_mtx			*meal_lock;
}					t_philo;

typedef struct s_program
{
	bool			dead_flag;
	t_mtx			dead_lock;
	t_mtx			meal_lock;
	t_mtx			write_lock;
	t_philo			*philos;
}					t_program;

// utils.c
void	error_exit(char *s);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	exit_mutexes(t_program *program, t_mtx *forks);
void	print_message(char *s, t_philo *philo);

// validate.c
void	validate_input(char **av);

// atol.c
long	ft_atol(char *s);

// init.c
void	init_structs(t_program *program, t_philo *philos,
			t_mtx *forks, char **av);

// dinner.c
void	start_dinner(t_program *program, t_mtx *forks);

// philo_actions.c
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);

// monitoring_utils.c
bool	ate_all_meals(t_philo *philos);
bool	philo_died(t_philo *philos);

#endif