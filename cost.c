/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:34:23 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/24 17:16:29 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int find_dist(int size, int id)
{
    int dist;

    dist = 1;
    if (size % 2 == 0)
    {
        if (id > size / 2)
            dist = dist - id + 1;
        else
            dist = id + 1;
    }
    else
    {
        if (id > size / 2)
            dist = size - id + 1;
        else if (id == size)
            dist = size - id;
        else
            dist = id + 1;
    }
    return (dist);
}

void    scan_all_stack(t_lst **stack)
{
    int hold_first;
    int hold_second;
    t_lst   *tmp;
    // int smallest_value;

    hold_first = ft_lstmin(&(*stack)->a)->content;
    tmp = (*stack);
    while (tmp->a->next)
    {
        if (hold_first < 10)
            hold_second = tmp->a->content;
        tmp->a = tmp->a->next;
    }
    printf("first : %d\n", hold_second);
}

// Stocker dans un tableau toutes les valeurs de la stack_a
// Utiliser le tableau comme outil d indexation

// void    ft_stack_tab(t_lst **stack)
// {
//     t_lst   *tab;
//     t_obj o = {0};
//     t_lst   *tmp;

//     tmp = (*stack);
//     tab = malloc(sizeof(t_lst));
//     if (!tab)
//         return ;
//     while (o.i++ <= tmp->a->content)
//     {
//         tab->stack_tab[o.i] = tmp->a->content++;
//         tmp->a = tmp->a->next;
//     }
//     while (o.i < (*stack)->a->pos)
//     {
//         printf("%d\n", tab->stack_tab[o.i++]);
//     }
//     // return (tab);
// }

void    move_smallest(t_lst **stack)
{
    int small_id;
    int smallest_value;
    int stack_len;
    
    small_id = ft_smallest_value(&(*stack)->a);
    smallest_value = ft_lstmin(&(*stack)->a)->content;
    stack_len = ft_set_id(&(*stack)->a);
    if (small_id <= stack_len / 2)
    {
        while ((*stack)->a->content != smallest_value)
        {
            ft_rrotate_a(&(*stack)->a, "rra", (*stack));
        }
    }
}

