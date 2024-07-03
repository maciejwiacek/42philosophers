/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:47:47 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 16:55:58 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philosopher(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf(Y"%zu my thread_id is: %lu\n"RST, philo->id, philo->thread_id);
	return (NULL);
}
