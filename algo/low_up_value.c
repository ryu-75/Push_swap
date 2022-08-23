/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_up_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:30:25 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/23 16:53:54 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Stack pos of smallest value in stack A
int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    while (ft_lstmin(stack)->content < tmp->content)
        tmp = tmp->next;
    return (tmp->pos);
}

// Found the largest value in stack B
int ft_largest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    while (ft_lstmax(stack)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->id);
}

// Find smallest id is stack A
int small_id_finder(t_data **stack, int low_val)
{
    t_obj o = {.i = -1};
    int pos;
    
    while (*stack)
    {
        o.i++;
        if (low_val == (*stack)->content)
            pos = o.i;
        (*stack) = (*stack)->next;
    }
    return (pos);
}

// Find largest id is stack A
int big_id_finder(t_data **stack, int hi_val)
{
    t_obj o = {.i = -1};
    int pos;
    
    while ((*stack))
    {
        o.i++;
        if (hi_val == (*stack)->content)
            pos = o.i;
        (*stack) = (*stack)->next;
    }
    return (pos);
}