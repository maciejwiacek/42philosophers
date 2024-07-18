/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:05:10 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 15:33:21 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	validate_input(char **av)
{
	if (ft_atol(av[1]) < 1 || ft_atol(av[1]) > MAX_PHILOS)
		error_exit("Number of philos incorrect!");
	if (ft_atol(av[2]) < 60)
		error_exit("Time to die incorrect!");
	if (ft_atol(av[3]) < 60)
		error_exit("Time to eat incorrect!");
	if (ft_atol(av[4]) < 60)
		error_exit("Time to sleep incorrect!");
	if (av[5] && ft_atol(av[5]) < 1)
		error_exit("Number of meals incorrect!");
}
