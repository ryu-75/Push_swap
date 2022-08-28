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

int ft_lstlen(t_data **stack)
{
    t_obj o = {0};
    t_data   *tmp;

    tmp = (*stack);
    while (tmp)
    {
        tmp->pos = o.i++;
        tmp = tmp->next;
    }
    return (o.i);
}

int  ft_tablen(char **av)
{
    t_obj o = {0};
    
    while (*av++)
        o.i++;
    o.i--;
    return (o.i);
}

// static void    ft_last_op(t_data **stack_a, t_data *min)
// {
//     while (min->cost > 0)
//     {
//         ft_rotate(stack_a, "ra");
//         min->cost--;
//     }
//     while (min->cost < 0)
//     {
//         ft_rrotate(stack_a, "rra");
//         min->cost++;
//     }
// }

void    last_sort(t_data **stack_a)
{
    // t_data  *min;

    // min = ft_lstmin(stack_a);
    ft_set_pos(stack_a);
    ft_set_cost(stack_a);
    // ft_last_op(stack_a, min);
}