/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:56 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/07 11:20:25 by nlorion          ###   ########.fr       */
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
            return (*nb1 - *nb2);
        if (*nb1 == '\0')
            return (0);
        nb1++;
        nb2++;
    }
    return (1);
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

int    ft_error()
{
    return((write(1, "Error\n", 6), exit(1), 0));
}