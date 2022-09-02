/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:56 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 17:03:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Compare each value
int	ft_strcmp(const char *nb1, const char *nb2)
{
	size_t	len;

	len = ft_strlen(nb2);
	while (len-- > 0)
	{
		if (*nb1 != *nb2)
			return (1);
		if (*nb1 == '\0')
			return (0);
		nb1++;
		nb2++;
	}
	return (0);
}

int	is_num(char *str)
{
	if ((*str == '-' || *str == '+') && ft_strlen(str) > 1)
		str++;
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	have_num(char *s)
{
	while (*s != 0)
	{
		if (ft_isdigit(*s) && *s != 46)
			return (1);
		s++;
	}
	return (0);
}

// Convert char like atoi but long long
long	ft_atols(const char *nptr)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*nptr == 32 || (*nptr >= 7 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (write(1, "Error\n", 6), exit(1), 0);
	return (result);
}

// Return an error if it doesn't work
int	ft_error(t_data **stack, int arg)
{
	arg = EXIT_FAILURE;
	ft_clear_stack(stack, NULL);
	if (arg)
		write(1, "Error\n", 6);
	return (exit(1), EXIT_FAILURE);
}
