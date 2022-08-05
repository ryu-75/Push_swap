/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:27 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/05 14:53:51 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Retrieve index of each value in stack 
int ft_set_id(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = (*stack);
	while (pos && pos->next)
    {
        pos->id = o.i++;
        pos = pos->next;
	}
	pos->id = o.i;
    return (o.i + 1);
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