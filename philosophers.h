/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:43 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:34:59 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define PHILOS_MAX 200

# include "./library/includes/get_next_line.h"
# include "./library/includes/printf.h"
# include "./library/includes/libft.h"
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			has_to_eat;
	size_t			meals_eaten;
	size_t			last_meal;
	size_t			timestamp;
	bool			is_eating;
	pthread_mutex_t	*lock_dead;
	pthread_mutex_t	*lock_write;
	pthread_mutex_t	*lock_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	bool			*is_dead;
}	t_philo;

typedef struct s_observer
{
	pthread_t		thread;
	t_philo			*philos;
	bool			is_dead;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock_meal;
}	t_observer;

void	init_forks(char **argv, pthread_mutex_t *forks);
void	observer_init(t_observer *observer, t_philo *philos);
void	philo_init(char **argv, t_observer observer, t_philo *philos, pthread_mutex_t *forks);
int		create_threads(t_observer observer, t_philo *philos);
void	*handle_observer(void *data);
void	*handle_philo(void *data);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	print_message(char *s, t_philo *philo, size_t timestamp);
size_t	now(void);

#endif