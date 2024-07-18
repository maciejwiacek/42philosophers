/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:08:17 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 21:45:37 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	check_for_dead(t_philo *philo)
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
	{
		if (ate_all_meals(philos) || philo_died(philos))
			break ;
	}
	return (data);
}

static void	*philo_handler(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_for_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (data);
}

void	start_dinner(t_program *program, t_mtx *forks)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	if (pthread_create(&monitor, NULL, monitoring, program->philos) != 0)
		exit_mutexes(program, forks);
	while (++i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL,
				philo_handler, &program->philos[i]) != 0)
			exit_mutexes(program, forks);
	}
	i = -1;
	if (pthread_join(monitor, NULL) != 0)
		exit_mutexes(program, forks);
	while (++i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			exit_mutexes(program, forks);
	}
}
