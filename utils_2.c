/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:46:54 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/19 11:46:54 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

// Return tab length 
int ft_tablen(int *tab)
{
    t_obj o = {0};

    if (!tab)
        return (0);
    while (tab[o.i])
        o.i++;
    return (o.i);
}