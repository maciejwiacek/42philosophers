/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:36:09 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 02:10:40 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	ate_all_meals(t_philo *philos)
{
	int	i;
	int	full_count;

	i = 0;
	full_count = 0;
	if (philos[0].num_times_to_eat < 1)
		return (false);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			full_count++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (full_count == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = true;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (true);
	}
	return (true);
}

static bool	did_starve(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (current_time() - philo->last_meal >= philo->time_to_die && philo->eating == false)
		return (pthread_mutex_unlock(philo->meal_lock), true);
	return (pthread_mutex_unlock(philo->meal_lock), false);
}

bool	died(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (did_starve(&philos[i]))
		{
			print_message("died", &philos[i]);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = true;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (true);
		}
		i++;
	}
	return (false);
}