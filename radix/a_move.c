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
void    ft_swap(t_data **stack, char *s, t_data *data)
{
    t_data  *tmp;
    tmp = NULL;
    if (!(*stack) || !stack)
        return ;
    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    tmp->next = (*stack);
    *stack = tmp;
    if (s)
        ft_ops(s, data);
}

// Push the first element from stack_b to stack_a
void    ft_push_a(t_data **stack_b, t_data **stack_a, char *s, t_data *data)
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

void    ft_push_b(t_data **stack_a, t_data **stack_b, char *s, t_data *data)
{
    t_data  *tmp;

    tmp = NULL;
    if (stack_a)
    {
        tmp = (*stack_a);
        (*stack_a) = tmp->next;
        tmp->next = (*stack_b);
        (*stack_b) = tmp;
    }
    if (s)
        ft_ops(s, data);
}

// Shift up all element at the top by 1 of stack_a
// The first element begin the last
void    ft_rotate(t_data **stack, char *s, t_data *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack))
        return ;
    tmp = (*stack);
    ft_lstadd_back_value(stack, add_newlst((*stack), tmp->content));
    ft_del_firstel(stack);
    if (s)
        ft_ops(s, data);
}

// Shift up all element at the top by 1 of stack_b
// The last element begin the first one
void    ft_rrotate(t_data **stack, char *s, t_data *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack))
        return ;
    tmp = (*stack);
    while (tmp->next)
        tmp = tmp->next;
    ft_addfront(stack, add_newlst((*stack), tmp->content));
    ft_del_lastel(stack);
    if (s)
        ft_ops(s, data);
}