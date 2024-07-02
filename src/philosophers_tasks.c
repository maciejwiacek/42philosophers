/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_tasks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:12:16 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:37:24 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	thinking(t_philo *philo)
{
	print_message("is thinking", philo, now());
}

void	sleeping(t_philo *philo)
{
	usleep(philo->time_to_sleep * 1000);
	print_message("is sleeping", philo, now());
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meal);
	philo->is_eating = true;
	pthread_mutex_lock(philo->r_fork);
	print_message("has taken a fork", philo, now());
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, now());
	usleep(philo->time_to_eat * 1000);
	print_message("is eating", philo, now());
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->last_meal = now();
	philo->meals_eaten++;
	philo->is_eating = false;
	pthread_mutex_unlock(philo->lock_meal);
}
