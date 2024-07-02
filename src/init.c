/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:48:12 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:17:56 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	init_forks(char **argv, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	observer_init(t_observer *observer, t_philo *philos)
{
	observer->is_dead = false;
	observer->philos = philos;
	pthread_mutex_init(&observer->lock_dead, NULL);
	pthread_mutex_init(&observer->lock_meal, NULL);
	pthread_mutex_init(&observer->lock_write, NULL);
}

void	philo_init(char **argv, t_observer observer,
					t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].num_of_philos = ft_atoi(argv[1]);
		philos[i].time_to_die = ft_atoi(argv[2]);
		philos[i].time_to_eat = ft_atoi(argv[3]);
		philos[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].timestamp = now();
		if (argv[5])
			philos[i].has_to_eat = ft_atoi(argv[5]);
		philos[i].lock_dead = &observer.lock_dead;
		philos[i].lock_write = &observer.lock_write;
		philos[i].lock_meal = &observer.lock_meal;
		philos[i].r_fork = &forks[i];
		if (i == 0)
			philos[i].l_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].l_fork = &forks[i - 1];
		philos[i].is_dead = &observer.is_dead;
		philos[i].last_meal = now();
		philos[i].is_eating = false;
		philos[i].meals_eaten = 0;
		i++;
	}
}
