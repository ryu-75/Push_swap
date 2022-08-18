/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:43 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/18 18:25:19 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int ft_min_content(t_data **stack)
{
    t_data  *tmp;
    t_data  *min;
    
    tmp = *stack;
    min = tmp;
    while (tmp)
    {
        if (tmp->content < min->content)
            min = tmp;
        tmp = tmp->next;
    }
    return (min->content);
}

// static int ft_id_min(t_data **stack)
// {
//     t_data  *tmp;
//     t_data  *min;
//     t_obj o = {0};
    
//     tmp = *stack;
//     min = tmp;
//     while (tmp)
//     {
//         if (tmp->idx < min->idx && o.i < ft_lsize(*stack))
//             min->idx = o.i++;
//         tmp = tmp->next;
//     }
//         printf("%d\n", min->idx);
//     return (min->idx);
// }

void    ft_move_3(t_data **stack)
{
    if ((*stack)->idx == 0 && (*stack)->next->idx != 1)
    {
        ft_rotate(stack, "ra", *stack);
        ft_swap(stack, "sa", *stack);
        ft_rrotate(stack, "rra", *stack);
    }
    else if ((*stack)->idx == 1)
    {
        if ((*stack)->next->idx == 0)
            ft_swap(stack, "sa", *stack);
        else
            ft_rrotate(stack, "rra", *stack);
    }
    else
    {
        if ((*stack)->next->idx == 0)
            ft_rotate(stack, "ra", *stack);
        else
        {
            ft_swap(stack, "sa", *stack);
            ft_rrotate(stack, "rra", *stack);
        }
    }
}

static void    ft_move_small(t_data **stack_a, t_data **stack_b)
{
    int min;
    int len;
    
    len = ft_set_pos(stack_a);
    min = ft_min_content(stack_a);
    if (min > len / 2)
    {
        while ((*stack_a)->content != min)
            ft_rotate(stack_a, "ra", *stack_a);
    }
    else if (min <= len / 2)
    {
        while ((*stack_a)->content != min)
            ft_rrotate(stack_a, "rra", *stack_a);
    }
    ft_push_b(stack_a, stack_b, "pb", *stack_a);
}

void    ft_move_4_5(t_data **stack_a, t_data **stack_b)
{
    int id;

    id = ft_set_pos(stack_a);
    if (ft_lst_is_sort(stack_a))
        return (exit(0));
    if (id == 4)
    {
        ft_move_small(stack_a, stack_b);
        ft_move_3(stack_a);
        // ft_push_a(stack_b, stack_a, "pa", *stack_b);
    }
    else if (id == 5)
    {
        ft_move_small(stack_a, stack_b);
        ft_move_small(stack_a, stack_b);
        ft_move_3(stack_a);
        ft_push_a(stack_b, stack_a, "pa", *stack_b);
        ft_push_a(stack_b, stack_a, "pa", *stack_b);
    }
}

void    ft_small_sort(t_data **stack_a, t_data **stack_b)
{
    int id;

    index_it(stack_a);
    id = ft_set_pos(stack_a);
    printf("%d\n", id);
    if (ft_lst_is_sort(stack_a))
        return ;
    if (id == 2)
        ft_swap(stack_a, "sa", *stack_a);
    else if (id == 3)
        ft_move_3(stack_a);
    if (id <= 5)
        ft_move_4_5(stack_a, stack_b);  
}

// 2 3 1 OK
// 3 2 1 OK
// 2 1 3 OK
// 3 1 2 OK
// 1 3 2 NOP

/**
 *  Optimiser sort 3. Bugue apres appel de la fonction small_move.
 *  Changer le head->idx pars head->content ?
 *  Voir avec la taille minimal du content et de l idx
 * 
 */