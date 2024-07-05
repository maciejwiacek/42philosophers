/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:51:24 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 01:29:53 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = false;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	program->philos = philos;
}

static void	init_forks(t_mtx *forks, int num_of_forks)
{
	int	i;

	i = 0;
	while (i < num_of_forks)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

static void	init_av(t_philo *philo, char **av)
{
	philo->num_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->num_times_to_eat = ft_atoi(av[5]);
	else
		philo->num_times_to_eat = -1;
}

static void	init_philos(t_program *program, t_philo *philos, t_mtx *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = false;
		philos[i].meals_eaten = 0;
		init_av(&philos[i], av);
		philos[i].last_meal = current_time();
		philos[i].start_time = current_time();
		philos[i].dead = &program->dead_flag;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		i++;
	}
}

void	parse_input(t_program *program, t_philo *philos, t_mtx *forks, char **av)
{
	init_program(program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(program, philos, forks, av);
	printf(G"Initialization successful\n"RST);
}