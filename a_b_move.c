/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/28 23:23:12 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void    ft_rotate_2(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    (*stack) = (*stack)->next;
    ft_lstadd_back_value(stack, tmp);
    tmp->next = NULL;
}

static void    ft_rrotate_2(t_data **stack)
{
    t_data  *tmp;
    t_data  *new;

    if ((*stack) && (*stack)->next)
    {
        tmp = (*stack);
        while ((*stack)->next->next)
            (*stack) = (*stack)->next; // tmp = 11
        new = (*stack)->next;
        (*stack)->next = NULL;
        new->next = tmp;
        (*stack) = new;
    }
}

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **a, t_data **b)
{
    t_data  *t_a;
    t_data  *t_b;

    t_a = *a;
    t_b = *b;
    ft_rrotate_2(&t_a);
    ft_rrotate_2(&t_b);
    ft_putstr_fd("rrr\n", 0);
}

// Stack a and stack b reverse rotate at the same time
void    rr_movement(t_data **a, t_data **b)
{
    t_data  *t_a;
    t_data  *t_b;

    t_a = *a;
    t_b = *b;
    ft_rotate_2(&t_a);
    ft_rotate_2(&t_b);
    ft_putstr_fd("rr\n", 0);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **a, t_data **b)
{
    ft_swap(a, "sa");
    ft_swap(b, "sb");
    write (1, "ss", 2);
    ft_putstr_fd("ss\n", 0);
}