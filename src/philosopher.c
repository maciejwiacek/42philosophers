/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:59:29 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 15:30:26 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*handle_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (*philo->is_dead == false)
	{
		if (philo->id % 2 == 0)
			usleep(1);
		thinking(philo);
		sleeping(philo);
		eating(philo);
	}
	return (NULL);
}
