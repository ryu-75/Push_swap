/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:54 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/16 14:05:54 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Recuperer la plus petite valeur.
// Commencer un premier trie de 3 en se basant des index recuperer avec la fonction "ft_position"
// Puis un second de 5
// Verifier d autre posibilite 


int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = (*stack);
    while (ft_lstmin(stack)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->id);
}

void    ft_sorted_three(t_lst **stack)
{
    int id;
    
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
    else if (id == 1)
    {
        if (&(*stack)->a->content > &(*stack)->a->next->next->content)
            ft_rotate_a(&(*stack)->a, "ra", (*stack));
        else
            ft_swap_a(&(*stack)->a, "sa", (*stack));
    }
}

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
    ft_push_a(&(*stack)->b, &(*stack)->a, "pb", (*stack));
}