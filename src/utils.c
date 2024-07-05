/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:47:14 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 01:30:15 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	error(char *s)
{
	printf(R"%s\n"RST, s);
	exit(EXIT_FAILURE);
}

bool	has_only_digits(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (false);
		s++;
	}
	return (true);
}

void	print_message(char *s, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d %s\n", current_time() - philo->start_time, philo->id, s);
	pthread_mutex_unlock(philo->write_lock);
}

size_t	current_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}