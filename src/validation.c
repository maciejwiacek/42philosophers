/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:37:39 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 16:00:11 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	validate_input(char **av)
{
	if (!(has_only_digits(av[1]) && ft_atoi(av[1]) > 0
			&& ft_atoi(av[1]) <= MAX_PHILOS))
		error("Number of philos should be between 1 and 200");
	if (!(has_only_digits(av[2]) && ft_atoi(av[2]) > 0))
		error("Time to die should be more than 0");
	if (!(has_only_digits(av[3]) && ft_atoi(av[3]) > 0))
		error("Time to eat should be more than 0");
	if (!(has_only_digits(av[4]) && ft_atoi(av[4]) > 0))
		error("Time to sleep should be more than 0");
	if (av[5] && !(has_only_digits(av[5]) && ft_atoi(av[5]) > 1))
		error("Number of meals for philosophers should be more than 0");
}
