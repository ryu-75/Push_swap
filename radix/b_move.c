/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:31 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 16:08:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Swap the first element with the second one
void    ft_swap_b(t_data **stack_b, char *s, t_lst *data)
{
    t_data  *tmp;

    tmp = NULL;
    if (!(*stack_b) || !stack_b)
        return ;
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = (*stack_b);
    *stack_b = tmp;
    if (s)
        ft_ops(s, data);
}

// Push the first element from stack _b to stack_a
void    ft_push_b(t_data **stack_a, t_data **stack_b, char *s, t_lst *data)
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

// Shift up all element at the top by 1 of stack_b
// The first element begin the last
void    ft_rotate_b(t_data **stack_b, char *s, t_lst *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_b))
        return ;
    tmp = (*stack_b);
    while (tmp->content < 1)
        tmp = tmp->next;
    ft_lstadd_back_value(stack_b, add_newlst((*stack_b), tmp->content));
    ft_del_firstel(stack_b);
    if (s)
        ft_ops(s, data);
}

// Shift up all element at the top by 1 of stack_a
// The last element begin the first one
void    ft_rrotate_b(t_data **stack_b, char *s, t_lst *data)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_b))
        return ;
    tmp = (*stack_b);
    while (tmp->next)
        tmp = tmp->next;
    ft_addfront(stack_b, add_newlst((*stack_b), tmp->content));
    ft_del_lastel(stack_b);
    if (s)
        ft_ops(s, data);
}