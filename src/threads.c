/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:26 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:28:23 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	create_threads(t_observer observer, t_philo *philos)
{
	size_t	i;

	i = 0;
	if (pthread_create(&observer.thread, NULL, handle_observer, &observer) != 0)
		return (ft_putstr_fd("Failed to create observer thread\n", 2), 1);
	while (i < philos[0].num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &handle_philo, &philos[i]) != 0)
			return (ft_putstr_fd("Failed to create philosopher thread\n", 2),
				1);
		i++;
	}
	i = 0;
	pthread_join(observer.thread, NULL);
	while (i < philos[0].num_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}
