/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:43 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/18 01:38:50 by nlorion          ###   ########.fr       */
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
    return (min->idx);
}

void    ft_move_3(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    if (ft_lst_is_sort(stack))
        return (exit(0));
    if (ft_id_min(stack, -1) + 2)
    {
        if (tmp->content > tmp->next->content)
            ft_swap(stack, "sa", *stack);
        ft_rrotate(stack, "rra", *stack);
    }
    else if (ft_id_min(stack, -1))
    {
        ft_swap(stack, "sa", *stack);
        ft_rotate(stack, "ra", *stack);
    }
    else
    {
        if (tmp->content > tmp->next->next->content)
            ft_rotate(stack, "rra", *stack);
        else
            ft_swap(stack, "sa", *stack);
    }
}

// void    ft_move_3(t_data **stack)
// {
//     t_data  *head;
//     int min;
//     int nextmin;
    
//     min = ft_id_min(stack, -1);
//     nextmin = ft_id_min(stack, min);
//     head = *stack;
//     if (head->idx == min && head->next->idx != nextmin)
//     {
//         ft_rotate(stack, "ra", *stack);
//         ft_swap(stack, "sa", *stack);
//         ft_rrotate(stack, "ra", *stack);
//     }
//     else if (head->idx == nextmin)
//     {
//         if (head->next->idx == min)
//             ft_swap(stack, "sa", *stack);
//         else
//             ft_rrotate(stack, "ra", *stack);
//     }
//     else
//     {
//         if (head->next->idx == min)
//             ft_rotate(stack, "ra", *stack);
//         else
//         {
//             ft_swap(stack, "ra", *stack);
//             ft_rrotate(stack, "rra", *stack);
//         }
//     }
// }

// void    ft_move_3(t_data **stack)
// {
//     t_data  *tmp;
//     int min;
//     int nxt_min;
    
//     min = ft_id_min(stack, -1); // 1
//     nxt_min = ft_id_min(stack, min); // 0
//     tmp = *stack;
//     index_it(stack);
//     if (ft_lst_is_sort(stack))
//         return ;
//     if (tmp->idx == min && tmp->next->idx != nxt_min)
//     {
//         ft_rotate(stack, "ra", *stack);
//         ft_swap(stack, "sa", *stack);
//         ft_rrotate(stack, "rra", *stack);
//     }
//     else if (tmp->next->idx == nxt_min)
//     {
//         if (tmp->idx > tmp->next->next->idx)
//         {
//             ft_swap(stack, "sa", *stack);
//             ft_rrotate(stack, "ra", *stack);
//         }
//     }
//     else if (tmp->next->idx == min)
//     {
//         ft_rotate(stack, "ra", *stack);
//         ft_swap(stack, "sa", *stack);
//     }
// }

// Found best trick and write less line as if possible 

// 3 2 1 OK
// 2 1 3 NOP
// 3 1 2 NOP
// 2 3 1 OK
// 1 3 2 OK