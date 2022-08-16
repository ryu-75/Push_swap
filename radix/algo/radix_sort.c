/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:53 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/16 19:08:06 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_max_bits(t_lst *stack)
{
    t_data  *tmp;
    int max_bits;
    int max_num;

    max_num = ft_set_id(stack);
    max_bits = 0;
    tmp = stack->a;
    if (tmp)
    {
        tmp = stack->a;
        while (tmp->next)
        {
            if (max_num >> max_bits != 0)
                max_bits++;
            tmp = tmp->next;
        }
    }
    return (max_bits);
}

void    radix_sort(t_lst *stack_a, t_lst *stack_b)
{
    int size;
    int max_bits;
    t_obj o = {0};
    (void) stack_b;

    size = ft_lsize(stack_a->a);
    max_bits = get_max_bits(stack_a);
    while (o.i < max_bits)
    {
        while (o.j < size)
        {
            if (((stack_a->a->content >> o.i) & 1) == 1)
                ft_rotate_a(&(stack_a)->a, "ra", stack_a);
            else
                ft_push_b(&(stack_a)->a, &(stack_a)->b, "pb", stack_a);
            o.j++;
        }
        while (ft_lsize(stack_a->b) != 0)
            ft_push_a(&(stack_a)->b, &(stack_a)->a, "pa", stack_a);
        o.i++;
    }
    printf("%d\n",max_bits);
}