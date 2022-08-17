/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:21:07 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/17 17:23:00 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int get_index_max(t_data *stack)
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
    return (max->idx);
}

t_data  *hash_list(t_data **stack)
{
    t_data  *tmp;
    t_data  *min;
    int min_found;

    min = NULL;
    min_found = 0;
    tmp = *stack;
    if (tmp)
    {
        while (tmp)
        {
            if ((tmp->idx == -1) && (!min_found || tmp->content < min->content))
            {
                min = tmp;
                min_found = 1;
            }
            tmp = tmp->next;
        }
    }
    return (min);
}

void    index_it(t_data **stack)
{
    t_data  *tmp;
    int index;

    index = 0;
    tmp = hash_list(stack);
    while (tmp)
    {
        tmp->idx = index++;
        tmp = hash_list(stack);
    }
}