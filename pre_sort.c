/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/22 10:59:15 by nlorion          ###   ########.fr       */
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
    t_obj o = {0};

    tmp = (*stack);
    while (tmp->a->next)
    {
        tmp->a = tmp->a->next;
        o.i++;
    }
    printf("begin = %d\n", tmp->a->content);
    while (o.i > tmp->size_a)
    {
        tmp->a = tmp->a->next;
    }
    printf("end = %d\n", tmp->a->content);
}