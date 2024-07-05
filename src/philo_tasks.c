/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tasks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:22:09 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 02:06:19 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_think(t_philo *philo)
{
	print_message("is thinking 🧐🧐🧐", philo);
}

void	ft_sleep(t_philo *philo)
{
	print_message("is sleeping 😴😴😴", philo);
	usleep(philo->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		usleep(philo->time_to_die * 1000);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo);
	philo->eating = true;
	print_message("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = current_time();
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat * 1000);
	philo->eating = false;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}