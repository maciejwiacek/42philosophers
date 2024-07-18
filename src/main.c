/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:57:38 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 15:39:37 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_philo		philos[MAX_PHILOS];
	t_mtx		forks[MAX_PHILOS];

	if (ac == 5 || ac == 6)
	{
		validate_input(av);
		init_structs(&program, philos, forks, av);
	}
	else
		error_exit("Wrong number of arguments!");
}
