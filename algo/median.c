/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:27:10 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/25 17:33:41 by nlorion          ###   ########.fr       */
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
        if (tmp->idx < med)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void    ft_pre_sort2(t_data **a, t_data **b)
{
    t_obj o = {0};
    
    while (ft_lsize(*a) > 2 && o.i <= ft_lsize(*a))
    {
        ft_push_b(a, b, "b", *a);
        o.i++;
    }
}

void    ft_pre_sort(t_data **a, t_data **b)
{
    int mid_median;
    int hi_median;
    t_obj o = {0};
    
    mid_median = found_median(a);   // Ex pour 100 = 33
    hi_median = mid_median * 2;     // 66
    while (ft_is_chunck(a, hi_median) && o.i <= ft_lsize(*a))
    {
        if ((*a)->idx < mid_median)
            ft_rotate(a, "a", *a);
        if ((*a)->idx >= mid_median && (*a)->idx <= hi_median)
            ft_push_b(a, b, "b", *a);
        else if ((*a)->idx > hi_median)
        {
            ft_push_b(a, b, "b", *a);
            ft_rotate(b, "b", *b);
        }
        o.i++;
    }
    ft_pre_sort2(a, b);
}