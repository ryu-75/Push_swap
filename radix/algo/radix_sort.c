/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:53 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/17 17:36:29 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_max_bits(t_data **stack)
{
    t_data  *tmp;
    int max_bits;
    int max_num;

    max_bits = 0;
    tmp = *stack;
    max_num = get_index_max(*stack);
    while (tmp)
    {
        if (max_num >> max_bits != 0)
            max_bits++;
        tmp = tmp->next;
    }
    return (max_bits);
}

void    radix_sort(t_data **stack_a, t_data **stack_b)
{
    int size;
    int max_bits;
    t_obj o = {0};
    t_data  *tmp;

    tmp = *stack_a;
    size = ft_lsize(*stack_a);
    max_bits = get_max_bits(stack_a);
    while (o.i < max_bits)
    {
        o.j = 0;
        while (o.j++ < size)
        {
            if (((tmp->idx >> o.i) & 1) == 1)
                ft_rotate(stack_a, "ra", *stack_a);
            else
                ft_push_b(stack_a, stack_b, "pb", *stack_a);
        }
        while (ft_lsize(*stack_b) != 0)
            ft_push_a(stack_b, stack_a, "pa", *stack_b);
        o.i++;
    }
}