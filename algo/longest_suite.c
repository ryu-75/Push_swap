/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_suite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:54:37 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/10 16:25:37 by nlorion          ###   ########.fr       */
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
    t_data  *curr;
    int i; 

    i = 0;
    curr = stack->a;
    (void) ft_next_value(stack);
    while (curr && curr->next)
    {
        if (i < stack->size_a && curr->idx != -1)
            ft_push_b(&stack->a, &stack->b, "pb", stack);
        else if (curr->idx == 0)
            ft_rrotate_a(&stack->a, "ra", stack);
        curr = curr->next;
    }
}