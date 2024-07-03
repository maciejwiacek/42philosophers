/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 17:33:50 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	create_threads(t_table table, t_philo *philos)
{
	size_t	i;

	i = 0;
	while (i < table.philos_num)
	{
		if (i % 2 == 0)
			usleep(10);
		pthread_create(&philos[i].thread_id, NULL, philosopher, &philos[i]);
		// Clean up after threads creation failure
		i++;
	}
}

void	eating_start(t_table *table)
{
	size_t	i;

	i = 0;
	create_threads(*table, table->philos);
	while (i < table->philos_num)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
}
