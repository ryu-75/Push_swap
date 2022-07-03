/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:56 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/04 00:34:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compare each value
int ft_strcmp(char *nb1, char *nb2)
{
    size_t len;

    len = ft_strlen(nb1);
    while (len-- > 0)
    {
        if (*nb1 == *nb2)
            return (nb1 - nb2);
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

// Count each number
int ft_nblen(int value)
{
    int l;

    l = !value;
    while (value)
    {
        l++;
        value /= 10;
    }
    return (l);
}