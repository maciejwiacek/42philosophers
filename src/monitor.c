/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:46:40 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/03 16:49:32 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	printf(Y"Hello, I'm table"RST);
	return (NULL);
}
