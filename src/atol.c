/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwiacek <mwiacek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:18:20 by mwiacek           #+#    #+#             */
/*   Updated: 2024/07/18 15:31:36 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static char	*validate_string(char *s)
{
	int		len;
	char	*res;

	len = 0;
	while (is_space(*s))
		++s;
	if (*s == '+')
		++s;
	else if (*s == '-')
		error_exit("Input numbers should be positive!");
	if (!is_digit(*s))
		error_exit("Input number is incorrect!");
	res = s;
	while (is_digit(*s++))
		++len;
	if (len > 10)
		error_exit("Input number should fit inside an integer!");
	return (res);
}

long	ft_atol(char *s)
{
	long	num;

	num = 0;
	s = validate_string(s);
	while (is_digit(*s))
		num = num * 10 + (*s++ - '0');
	if (num > INT_MAX)
		error_exit("Input number should fit inside an integer!");
	return (num);
}
