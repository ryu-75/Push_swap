/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:43 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/17 20:06:06 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_id_min(t_data **stack, int val)
{
    t_data  *tmp;
    t_data  *min;
    t_obj o = {0};
    
    tmp = *stack;
    min = tmp;
    while (tmp && o.i < ft_lsize(*stack))
    {
        if (tmp->idx < min->idx && tmp->idx != val)
            min = tmp;
        tmp = tmp->next;
    }
    printf("%d\n", min->content);
    return (min->idx);
}

void    ft_move_3(t_data **stack)
{
    t_data  *tmp;
    int min;
    int nxt_min;
    
    min = ft_id_min(stack, -1); // 1
    nxt_min = ft_id_min(stack, min); // 0
    tmp = *stack;
    index_it(stack);
    if (ft_lst_is_sort(stack))
        return ;
    if (tmp->idx == min && tmp->next->idx != nxt_min)
    {
        ft_rotate(stack, "ra", *stack);
        ft_swap(stack, "sa", *stack);
        ft_rrotate(stack, "rra", *stack);
    }
    else if (tmp->next->idx == nxt_min)
    {
        if (tmp->idx > tmp->next->next->idx)
        {
            ft_swap(stack, "sa", *stack);
            ft_rrotate(stack, "ra", *stack);
        }
    }
    else if (tmp->next->idx == min)
    {
        ft_rotate(stack, "ra", *stack);
        ft_swap(stack, "sa", *stack);
    }
}

// Found best trick and write less line as if possible 

// 3 2 1 OK
// 2 1 3 NOP
// 3 1 2 NOP
// 2 3 1 OK
// 1 3 2 OK