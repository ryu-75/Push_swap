/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:36:59 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 16:08:36 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Swap the first element with the second one
void    ft_swap_a(t_data **stack_a, char *s, t_lst *data)
{
    t_data  *tmp;
    tmp = NULL;
    if (!(*stack_a) || !stack_a)
        return ;
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = (*stack_a);
    *stack_a = tmp;
    if (s)
        ft_ops(s, data);
}

// Push the first element from stack _a to stack_b
void    ft_push_a(t_data **stack_b, t_data **stack_a, char *s, t_lst *data)
{
    t_data  *tmp;
    tmp = NULL;
    if (stack_b)
    {
        tmp = (*stack_b);
        (*stack_b) = tmp->next;
        tmp->next = (*stack_a);
        (*stack_a) = tmp;
    }
    if (s)
        ft_ops(s, data);
}

// Shift up all element at the top by 1 of stack_a
// The first element begin the last
void    ft_rotate_a(t_data **stack_a, char *s, t_lst *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_a))
        return ;
    tmp = (*stack_a);
    ft_lstadd_back_value(stack_a, add_newlst((*stack_a), tmp->content));
    ft_del_firstel(stack_a);
    if (s)
        ft_ops(s, data);
}

// Shift up all element at the top by 1 of stack_b
// The last element begin the first one
void    ft_rrotate_a(t_data **stack_a, char *s, t_lst *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_a))
        return ;
    tmp = (*stack_a);
    while (tmp->next)
        tmp = tmp->next;
    ft_addfront(stack_a, add_newlst((*stack_a), tmp->content));
    ft_del_lastel(stack_a);
    if (s)
        ft_ops(s, data);
}