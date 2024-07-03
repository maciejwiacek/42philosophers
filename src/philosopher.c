/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:47:47 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 17:34:57 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	ph_think(t_philo *philo)
{
	printf(Y"🤔\t%lu %zu is thinking\t🤔\n"RST, current_time(), philo->id);
}

// static void	ph_sleep(t_philo *philo)
// {
// 	printf("%zu -> id\n", philo->id);
// 	printf(B"😴\t%lu %zu is sleeping\t😴\n"RST, current_time(), philo->id);
// 	usleep(philo->time_to_sleep * 1000);
// }

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		ph_think(philo);
	}
	return (NULL);
}
