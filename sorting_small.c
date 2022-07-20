/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:54 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 16:26:23 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Stack the smallest value
int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = (*stack);
    while (ft_lstmin(stack)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->id);
}

// This function allow to sort three number 
void    ft_sorted_three(t_lst **stack)
{
    int id;
    
    if (ft_lst_is_sort(&(*stack)->a))
        return ;
    ft_set_id(&(*stack)->a);
    id = ft_smallest_value(&(*stack)->a);
    if (id == 2)
    {   
        if ((*stack)->a->content > (*stack)->a->next->content)
            ft_swap_a(&(*stack)->a, "sa", (*stack));
        ft_rrotate_a(&(*stack)->a, "rra", (*stack));
    }
    else if (id == 0)
    {
        ft_swap_a(&(*stack)->a, "sa", (*stack));
        ft_rotate_a(&(*stack)->a, "ra", (*stack));
    }
    else
    {
        if ((*stack)->a->content > (*stack)->a->next->next->content)
            ft_rotate_a(&(*stack)->a, "rra", (*stack));
        else
            ft_swap_a(&(*stack)->a, "sa", (*stack));
    }
}

// Move to the top the most minimal value 
void    ft_small_move(t_lst **stack)
{
    int small_content;
    int smallest_id;
    int stack_len;

    stack_len = ft_set_id(&(*stack)->a);
    smallest_id = ft_smallest_value(&(*stack)->a);
    small_content = ft_lstmin(&(*stack)->a)->content;
    if (smallest_id > stack_len / 2)
    {
        while ((*stack)->a->content != small_content)
            ft_rrotate_a(&(*stack)->a, "rra", (*stack));
    }
    else if (smallest_id <= stack_len / 2)
    {
        while ((*stack)->a->content != small_content)
            ft_rotate_a(&(*stack)->a, "ra", (*stack));
    }
    ft_push_b(&(*stack)->a, &(*stack)->b, "pb", (*stack));
}

void    ft_sorting_five(t_lst **stack)
{
    int id;
    
    if (ft_lst_is_sort(&(*stack)->a))
        return ;
    id = ft_set_id(&(*stack)->a);
    if (id == 4)
    {
        ft_small_move(stack);
        ft_sorted_three(stack);
        ft_push_a(&(*stack)->b, &(*stack)->a, "pa", (*stack));
    }
    else if (id == 5)
    {
        ft_small_move(stack);
        ft_small_move(stack);
        ft_sorted_three(stack);
        ft_push_a(&(*stack)->b, &(*stack)->a, "pa", (*stack));
        ft_push_a(&(*stack)->b, &(*stack)->a, "pa", (*stack));
    }
}