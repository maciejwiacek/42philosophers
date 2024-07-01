/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:16 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/01 11:55:53 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	is_number(char *s)
{
	while (s)
		if (!ft_isdigit(*s++))
			return (false);
	return (true);
}

static bool	is_valid_input(char **argv)
{
	size_t	i;

	i = 2;
	if (!is_number(argv[1]) || ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (false);
	while(argv[i])
	{
		if (!is_number(argv[i]) || ft_atoi(argv[i]) < 1)
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc != 5 && argc != 6)
		return (ft_putstr_fd("Wrong number of arguments", 2), 1);

	ft_printf("Do a validation\n");
}