/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:34:23 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/25 12:31:42 by nlorion          ###   ########.fr       */
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

void    ft_stack_tab(t_lst **stack)
{
    t_obj o = {0};
    t_lst   *tmp;

    tmp = (*stack);
    (*stack)->stack_tab = malloc(sizeof(int) * tmp->a->size);
    if (!(*stack)->stack_tab)
        free((*stack)->stack_tab);
    while (tmp->a)
    {
        tmp->stack_tab[o.i] = tmp->a->content;
        o.i++;
        tmp->a = tmp->a->next;
    }
}

int *ft_sorting_tab(int *tab)
{
    t_obj o = {0};
    int tmp;
    
    tmp = 0;
    if (!tab)
        return(0);
    while (tab[o.i])
    {
        o.j = o.i + 1;
        while (tab[o.i] > tab[o.j])
        {
            tmp = tab[o.j];
            tab[o.j] = tab[o.i];
            tab[o.i] = tmp;
            o.j--;
        }
        o.i++;
    }
    return (tab);
}

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