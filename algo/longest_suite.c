/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:54:37 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/07 23:59:59 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_max_len(t_lst *stack)
{
    t_data  *tmp;
    int len;
    
    len = 0;
    tmp = stack->a;
    while (tmp)
    {
        if (len < tmp->count)
        {
            len = tmp->count;
            tmp->idx = -1;
        }
        else
            tmp->idx = 0;
        tmp = tmp->next;
    }
    return (len);
}

int ft_next_value(t_lst *stack)
{
    t_data  *curr_p;
    t_data  *prev_p;
    int max;
    int len;
    
    curr_p = stack->a->next;
    while (curr_p)
    {
        max = 0;
        prev_p = stack->a;
        while (prev_p != curr_p)
        {
            if (curr_p->content > prev_p->content)
                if (prev_p->count > max)
                    max = prev_p->count;
            prev_p = prev_p->next;
        }
        prev_p->count = max + 1;
        curr_p = curr_p->next;
    }
    len = find_max_len(stack);
    return (len);
}

void    pre_sort_2(t_lst *stack)
{
    t_data  *tmp_a;
    // t_obj o = {0};
    
    tmp_a = stack->a;
    while (tmp_a)
    {
        if (tmp_a->idx == 0)
            ft_push_b(&stack->a, &stack->b, "pb", stack);
        ft_rotate_a(&stack->a, "ra", stack);
        tmp_a = tmp_a->next;
    }
    (void) ft_next_value(stack);
}