/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/21 00:36:15 by nlorion          ###   ########.fr       */
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

t_lst   *ft_chunk_move(t_lst **stack)
{
    t_lst   *tmp;
    t_lst   *s_hold;

    tmp = (*stack);
    s_hold = tmp;
    while (tmp->a)
    {   
        if (tmp->size_a < 20)
        {
            if (tmp->a->content < s_hold->a->content)
                s_hold = tmp;
        }
        tmp->a = tmp->a->next;
    }
    // if (tmp->size_a)
    // {
    //     while (tmp->a->content)
    //     {
    //         if (tmp->a->content < s_hold->a->content && s_hold->a->content > tmp->a->hold_first)
    //             tmp->a->hold_second = tmp->a->content;
    //         tmp->a->content--;
    //         tmp->a = tmp->a->next;
    //     }
    // }
    return (s_hold);
}