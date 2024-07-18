/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:36:11 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 15:57:24 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = false;
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		error_exit("Failed creating mutex!");
	if (pthread_mutex_init(&program->meal_lock, NULL) != 0)
		error_exit("Failed creating mutex!");
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		error_exit("Failed creating mutex!");
	program->philos = philos;
}

static void	init_forks(t_mtx *forks, long num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			error_exit("Failed creating mutex!");
	}
}

static void	init_av(t_philo *philo, char **av)
{
	philo->num_of_philos = ft_atol(av[1]);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		philo->num_times_to_eat = ft_atol(av[5]);
	else
		philo->num_times_to_eat = -1;
}

static void	init_philos(t_program *program, t_philo *philos,
							t_mtx *forks, char **av)
{
	int	i;
	int	num_of_philos;

	i = -1;
	num_of_philos = ft_atol(av[1]);
	while (++i < num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = false;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_current_time();
		init_av(&philos[i], av);
		philos[i].start_time = get_current_time();
		philos[i].dead = &program->dead_flag;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
	}
}

void	init_structs(t_program *program, t_philo *philos,
						t_mtx *forks, char **av)
{
	init_program(program, philos);
	init_forks(forks, ft_atol(av[1]));
	init_philos(program, philos, forks, av);
}
