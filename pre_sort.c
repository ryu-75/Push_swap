/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/22 15:03:31 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// int find_median(t_lst **stack, int size) // ex : find_median(&(*stack), &(*stack)->a->data_size)
// {
//     t_lst *tmp;
//     t_obj o = {0};
//     int median;
// 
//     tmp = (*stack);
//     while (o.i < tmp->a->data_size)
//     {
//         if (size % 2 == 0)
//             median = t;
//     }
// }

void    ft_read_test(t_lst **stack)
{
    t_lst   *tmp;
    
    tmp = (*stack);
    tmp->a->hold_first = ft_lstmin(&(*stack)->a)->content;
    while (tmp->a)
    {
        tmp->a->hold_second = ft_lstmin(&(*stack)->a)->content;
        tmp->a = tmp->a->hold_second;
    }
    printf("first = %d\n", tmp->a->hold_first);
    printf("second = %d\n", tmp->a->hold_second);
}