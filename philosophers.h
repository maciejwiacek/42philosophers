/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:43 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 16:49:38 by mwiacek          ###   ########.fr       */
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

# define MAX_PHILOS 200

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	size_t	fork_id;
	t_mtx	fork;
}	t_fork;

typedef struct s_philo
{
	size_t		id;
	pthread_t	thread_id;
	size_t		meals_counter;
	bool		is_full;
	time_t		last_ate;
	t_fork		*l_fork;
	t_fork		*r_fork;
}	t_philo;

typedef struct s_table
{
	size_t	philos_num;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	size_t	meals_limit;
	time_t	start_time;
	bool	did_finish;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;

void	error(char *s);
void	validate_input(char **av);
void	parse_data(t_table *table, char **av);
bool	has_only_digits(char *s);
void	*philosopher(void *data);
void	*monitor(void *data);

#endif