/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:34:23 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/24 12:11:09 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int find_dist(int size, int id)
{
    int dist;

    dist = 1;
    if (size % 2 == 0)
    {
        if (id > size / 2)
            dist = dist - id + 1;
        else
            dist = id + 1;
    }
    else
    {
        if (id > size / 2)
            dist = size - id + 1;
        else if (id == size)
            dist = size - id;
        else
            dist = id + 1;
    }
    return (dist);
}

void    move_smallest(t_lst **stack)
{
    int small_id;
    int smallest_value;
    int stack_len;
    int dist;

    small_id = ft_smallest_value(&(*stack)->a);
    smallest_value = ft_lstmin(&(*stack)->a)->content;
    stack_len = ft_set_id(&(*stack)->a);
    dist = find_dist(ft_lstlen(&(*stack)->a), stack_len);
    if (small_id <= stack_len / 2)
    {
        while ((*stack)->a->content != smallest_value)
        {
            if (dist > 0)
                ft_rotate_a(&(*stack)->a, "rra", (*stack));
            else
                ft_rrotate_a(&(*stack)->a, "rra", (*stack));
        }
    }
}