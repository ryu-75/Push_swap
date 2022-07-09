/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:56 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/09 16:42:15 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compare each value
int ft_strcmp(const char *nb1, const char *nb2)
{
    size_t len;

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

// Return len tab 
size_t ft_tablen(int *tab)
{
    int i;

    i = 0;
    if (!(tab))
        return (0);
    while (tab++)
        i++;
    return (i);
}

int have_num(char *s)
{
    while (*s != 0)
    {
        if (ft_isdigit(*s))
            return (1);
        s++;
    }
    return (0);
}

// Count each number
int ft_nblen(int value)
{
    t_obj o = {0};
    
    while (value != 0)
    {
        value /= 10;
        o.i++;   
    }
    return (o.i);
}

// Convert char like atoi but long long
long long	ft_convert_value(const char *nptr)
{
	long long	result;
	int	sign;

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

void    ft_error()
{
    write(1, "Error\n", 6);
    EXIT_FAILURE;
}