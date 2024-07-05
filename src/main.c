/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:23 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/05 01:15:20 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int ac, char **av)
{
	t_program	program;
	t_philo		*philos;
	t_mtx		*forks;

	if (ac == 5 || ac == 6)
	{
		philos = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		forks = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		validate_input(av);
		parse_input(&program, philos, forks, av);
		start_loop(&program);
		free(philos);
		free(forks);
	}
	else
	{
		error("Wrong number of arguments");
	}
}
