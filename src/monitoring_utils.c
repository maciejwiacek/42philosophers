/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:20:53 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 21:37:08 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ate_all_meals(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat < 1)
		return (false);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		++i;
	}
	if (philos[0].num_of_philos == finished_eating)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = true;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (true);
	}
	return (false);
}

static bool	philo_starved(t_philo *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->meal_lock);
	last_meal = get_current_time() - philo->last_meal;
	if (last_meal >= philo->time_to_die && !philo->eating)
		return(pthread_mutex_unlock(philo->meal_lock), true);
	return (pthread_mutex_unlock(philo->meal_lock), false);
}

bool	philo_died(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].num_of_philos)
	{
		if (philo_starved(&philos[i]))
		{
			print_message("died", &philos[i]);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos->dead = true;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (true);
		}
	}
	return (false);
}
