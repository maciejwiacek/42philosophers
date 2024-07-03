/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:36:25 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 17:32:49 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	init_forks(t_table *table, size_t forks_count)
{
	t_fork	forks[MAX_PHILOS];
	size_t	i;

	i = 0;
	while (i < forks_count)
	{
		if (pthread_mutex_init(&forks[i].fork, NULL) != 0)
			error("Mutex creation failed");
		forks[i].fork_id = i + 1;
		i++;
	}
	table->forks = forks;
	printf(G"✅\tForks initialized successfully\t✅\n"RST);
}

static void	init_philos(t_table *table, size_t philos_count, char **av)
{
	t_philo	philos[MAX_PHILOS];
	size_t	i;

	i = 0;
	while (i < philos_count)
	{
		philos[i].id = i + 1;
		if (i % 2 == 0)
			usleep(1);
		if (av[5])
			philos[i].meals_counter = ft_atoi(av[5]);
		philos[i].is_full = false;
		philos[i].last_ate = current_time();
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		philos[i].l_fork = &table->forks[i];
		if (i == philos_count - 1)
			philos[i].r_fork = &table->forks[0];
		else
			philos[i].r_fork = &table->forks[i + 1];
		i++;
	}
	table->philos = philos;
	printf(G"✅\tPhilosophers initialized successfully\t✅\n"RST);
}

static void	init_table(t_table *table, char **av)
{
	table->philos_num = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->meals_limit = ft_atoi(av[5]);
	table->start_time = current_time();
	table->did_finish = false;
	printf(G"✅\tTables initialized successfully\t✅\n"RST);
}

void	parse_data(t_table *table, char **av)
{
	validate_input(av);
	init_forks(table, ft_atoi(av[1]));
	init_philos(table, ft_atoi(av[1]), av);
	init_table(table, av);
}
