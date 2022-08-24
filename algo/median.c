/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:27:10 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/24 17:21:22 by nlorion          ###   ########.fr       */
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
    int median;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->idx != med)
            median = tmp->idx;
        tmp = tmp->next;
    }
    return (median);
}

void    ft_pre_sort(t_data **a, t_data **b)
{
    int med_median;
    int hi_median;
    
    med_median = found_median(a);   // Ex pour 100 = 33
    hi_median = med_median * 2;     // 66
    while (!ft_is_chunck(a, hi_median))
    {
        if ((*a)->idx < med_median)
            ft_rotate(a, "ra", *a);
        if ((*a)->idx >= med_median && (*a)->idx <= hi_median)
            ft_push_b(a, b, "pb", *a);
        else if ((*a)->idx > hi_median)
        {
            ft_push_b(a, b, "pb", *a);
            ft_rotate(b, "rb", *b);
        }
    }
    while (ft_lsize(*a) > 2)
        ft_push_b(a, b, "pb", *a); 
}