/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:28:35 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 17:11:49 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	error(char *s)
{
	printf(R"🆘\t%s\t🆘\n"RST, s);
	exit(EXIT_FAILURE);
}

bool	has_only_digits(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

time_t	current_time(void)
{
	struct timeval	tp;
	time_t			time;

	if (gettimeofday(&tp, NULL) != 0)
		return (0);
	time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (time);
}
