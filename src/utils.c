/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:03:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 21:51:40 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	error_exit(char *s)
{
	printf("%s\n", s);
	exit(1);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	exit_mutexes(t_program *program, t_mtx *forks)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	while (++i < program->philos[0].num_of_philos)
		pthread_mutex_destroy(&forks[i]);
	error_exit("Mutex operation went wrong!");
}

void	print_message(char *s, t_philo *philo)
{
	size_t	time;

	time = get_current_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!check_for_dead(philo))
		printf("%zu %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(philo->write_lock);
}
