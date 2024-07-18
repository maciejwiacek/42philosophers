/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:55:38 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 21:41:15 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_think(t_philo *philo)
{
	print_message("is thinking", philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	philo->eating = true;
	print_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = false;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
