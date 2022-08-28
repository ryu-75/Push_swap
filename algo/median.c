/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:27:10 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/28 17:39:08 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int found_median(t_data **stack)
{
    t_data  *tmp;
    int size;

    tmp = (*stack);
    size = ft_set_pos(stack);
    index_it(stack);
    while (tmp)
    {
        if (tmp->idx == size / 3)
            return (tmp->idx);
        tmp = tmp->next;
    }
    return (0);
}

int ft_is_chunck(t_data **stack, int med)
{
    t_data  *tmp;
    
    tmp = *stack;
    while (tmp)
    {
        if (tmp->idx > med)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    ft_pre_sort(t_data **a, t_data **b)
{
    int mid_median;
    int hi_median;
    t_data  *t_a;

    t_a = *a;
    mid_median = found_median(a);   // Ex pour 100 = 33
    hi_median = mid_median * 2;     // 66
    while (!ft_is_chunck(a, mid_median))
    {
        if (t_a->idx < mid_median)
            ft_rotate(a, "a");
        if (t_a->idx >= mid_median && t_a->idx <= hi_median)
            ft_push_b(a, b);
        else if (t_a->idx > hi_median)
        {
            ft_push_b(a, b);
            ft_rotate(b, "b");
        }    
    }    
    while (ft_lsize(*a) > 2)
        ft_push_b(a, b);
}