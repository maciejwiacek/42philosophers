/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:36:21 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:35:47 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	did_die(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meal);
	if (now() - philo->last_meal >= philo->time_to_eat && !philo->is_eating)
	{
		pthread_mutex_unlock(philo->lock_meal);
		return (true);
	}
	pthread_mutex_unlock(philo->lock_meal);
	return (false);
}

static bool	is_dead(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo[0].num_of_philos)
	{
		if (did_die(&philo[i]))
		{
			print_message("died", &philo[i], now());
			pthread_mutex_lock(philo[0].lock_dead);
			*philo[0].is_dead = true;
			pthread_mutex_unlock(philo[0].lock_dead);
			return (true);
		}
		i++;
	}
	return (false);
}

void	*handle_observer(void *data)
{
	t_observer	observer;
	t_philo		*philos;

	observer = *(t_observer *)data;
	philos = observer.philos;
	while (1)
	{
		if (is_dead(philos))
			break;
	}
	return (philos);
}
