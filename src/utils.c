/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:32:12 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:36:26 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_message(char *s, t_philo *philo, size_t timestamp)
{
	pthread_mutex_lock(philo->lock_write);
	ft_printf("%d %d %s\n", timestamp, philo->id, s);
	pthread_mutex_unlock(philo->lock_write);
}

size_t	now(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		print_message("Couldn't get a time", NULL, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}