/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:50:13 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/16 18:30:38 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_data  *get_index_max(t_data *stack)
{
    t_data  *max_value;
    t_data  *max;
    t_obj o = {0};
    
    max_value = stack;
    max = stack;
    while (max_value && o.i < ft_lsize(stack))
    {
        if (max_value->content > max->idx - 1)
            max->idx = o.i;
        o.i++;
    }
    printf("%d\n", max->idx);
    return (max);
}

t_data  *get_next_min(t_data *stack)
{
    t_data  *tmp;
    t_data  *min;
    int min_val;

    min_val = 0;
    min = NULL;
    tmp = stack;
    if (tmp)
    {
        while (tmp)
        {
            if (tmp->idx == -1 && (!min_val || tmp->content < min->content))
            {
                min = tmp;
                min_val = 1;
            }
            tmp = tmp->next;
        }
    }
    return (min);
}



/**
 *  Trouver la valeur la plus petite
 *  Lui appliquer l index 0
 *  Ajouter 1 a chaque index superieur a la min value
 * 
 */