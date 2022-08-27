/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:52:08 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/27 17:48:36 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    use_rotate(t_data **stack, int cost, char *s)
{
    while (cost > 0)
    {
        if (*s == 'a')
            ft_rotate(stack, "ra");
        else
            ft_rotate(stack, "rb");
        (*stack)->cost--;
    }
}   

void    use_reverse(t_data **stack, int cost, char *s)
{
    while (cost > 0)
    {
        if (*s == 'a')
            ft_swap(stack, "sa");
        else
            ft_swap(stack, "sb");
        (*stack)->cost++;
    }
}

void    use_rrotate(t_data **stack_a, t_data **stack_b, int cost)
{
    while (cost > 0 || cost > 0)
    {
        ft_rotate(stack_a, "ra");
        ft_rotate(stack_b, "rb");
        (*stack_a)->cost--;
        (*stack_b)->cost--;
    }
}

void    use_rrr(t_data **stack_a, t_data **stack_b, int cost_a, int cost_b)
{
    while (cost_a < 0 && cost_b < 0)
    {
        ft_rrotate(stack_a, "rra");
        ft_rrotate(stack_b, "rrb");
        (*stack_a)->cost++;
        (*stack_b)->cost++; 
    }
}   

void    ft_final_move(t_data **stack_a, t_data **stack_b, int cost_a, int cost_b)
{
    while (cost_a != 0 || cost_b != 0)
    {
        if (cost_a > 0 && cost_b < 0)
            use_rotate(stack_a, cost_a, "ra");
        else if (cost_b > 0 && cost_a < 0)
            use_rotate(stack_b, cost_b, "rb");
        else if (cost_a < 0 && cost_b > 0)
            use_reverse(stack_a, cost_a, "sa");
        else if (cost_b < 0 && cost_a > 0)
            use_reverse(stack_b, cost_b, "sb");
        else if (cost_a > 0 && cost_b > 0)
            use_rrotate(stack_a, stack_b, cost_a);
        else if (cost_a < 0 && cost_b < 0)
            use_rrr(stack_a, stack_b, cost_a, cost_b);
        (*stack_a) = (*stack_a)->next;
    }   
}