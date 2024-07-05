/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:14:36 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 02:11:56 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	return (pthread_mutex_unlock(philo->dead_lock), false);
}

static void	*monitoring(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	while (1)
		if (died(philos) || ate_all_meals(philos))
			break;
	return (philos);
}

static void *philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!is_dead(philo))
	{
		ft_eat(philo);
		if (!is_dead(philo))
			ft_sleep(philo);
		if (!is_dead(philo))
			ft_think(philo);
	}
	return (NULL);
}

static void	create_threads(t_program *program)
{
	pthread_t	monitor;
	int			i;

	pthread_create(&monitor, NULL, &monitoring, program->philos);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_create(&program->philos[i].thread, NULL, &philosopher, &program->philos[i]);
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		pthread_join(program->philos[i].thread, NULL);
		i++;
	}
}

void	start_loop(t_program *program)
{
	create_threads(program);
}