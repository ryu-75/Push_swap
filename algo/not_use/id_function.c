/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:23:58 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/09 00:24:18 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void stack_id_a(t_lst  *stack)
{
    t_data  *tmp_a;

    tmp_a = stack->a;

    while (tmp_a->next && tmp_a->content)
    {
        tmp_a = tmp_a->next;
        stack->a->id = tmp_a->id;
    }
}

void stack_id_b(t_lst  *stack)
{
    t_data  *tmp_b;
    
    tmp_b = stack->b;
    while (tmp_b->next && tmp_b->content)
    {
        tmp_b = tmp_b->next;
        stack->b->id = tmp_b->id;
    }
}

// Register id of the max value
void    found_id_max(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->a;
    while (tmp->content != ft_lstmax(&stack->a)->content)
    {
        if (ft_lstmax(&stack->a)->content)
        {
            stack->a->id = stack->a->next->id;
            tmp->id = stack->a->id;
        }
        tmp = tmp->next;
    }
}

// Register id of the min value
void    found_id_min(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->a;
    while (tmp->content != ft_lstmin(&stack->a)->content)
    {
        if (ft_lstmax(&stack->a)->content)
        {
            stack->a->id = stack->a->next->id;
            tmp->id = stack->a->id;
        }
        tmp = tmp->next;
    }
}