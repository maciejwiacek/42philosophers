/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:43 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 01:43:19 by mwiacek          ###   ########.fr       */
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

# define RST "\033[0m"
# define R "\033[1;31m"
# define G "\033[1;32m"
# define B "\033[1;34m"
# define C "\033[1;36m"
# define M "\033[1;35m"
# define Y "\033[1;33m"
# define W "\033[1;37m"

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

bool	has_only_digits(char *s);
void	error(char *s);
void	print_message(char *s, t_philo *philo);
size_t	current_time(void);
void	validate_input(char **av);
void	parse_input(t_program *program, t_philo *philos, t_mtx *forks, char **av);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_eat(t_philo *philo);
bool	died(t_philo *philos);
bool	ate_all_meals(t_philo *philos);
void	start_loop(t_program *program);

#endif