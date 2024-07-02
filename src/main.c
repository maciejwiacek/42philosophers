/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:16 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/02 14:41:37 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	is_number(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_valid_input(char **argv)
{
	size_t	i;

	i = 2;
	if (!is_number(argv[1]) || ft_atoi(argv[1]) < 1
		|| ft_atoi(argv[1]) > PHILOS_MAX)
		return (false);
	while (argv[i])
	{
		if (i != 5 && (!is_number(argv[i]) || ft_atoi(argv[i]) < 60))
			return (false);
		if (i == 5 && (!is_number(argv[i]) || ft_atoi(argv[i]) < 0))
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_philo			philos[PHILOS_MAX];
	t_observer		observer;
	pthread_mutex_t	forks[PHILOS_MAX];

	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (!is_valid_input(argv))
		return (ft_putstr_fd("Your input is incorrect\n", 2), 1);
	observer_init(&observer, philos);
	init_forks(argv, forks);
	philo_init(argv, observer, philos, forks);
	create_threads(observer, philos);
}
