/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/08 13:23:47 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_stack_tab(t_lst **stack)
{
    t_obj o = {0};
    t_data   *tmp;

    free((*stack)->stack_tab);
    tmp = (*stack)->a;
    (*stack)->stack_tab = malloc(sizeof(int) * (int) (*stack)->size_tab);
    if (!(*stack)->stack_tab)
        free((*stack)->stack_tab);
    while (tmp)
    {
        (*stack)->stack_tab[o.i] = tmp->content;
        o.i++;
        tmp = tmp->next;
    }
}

int  found_median(int *tab, int size)
{
    int median;
    
    if (size % 2 == 0)
        median = tab[(size / 2) + 1];
    else
        median = tab[(size + 1) / 2];
    return (median);
}

void ft_sorting_tab(int *tab, int size)
{
    t_obj o = {0};
    int tmp;
    
    tmp = 0;
    while (o.i < size)
    {
        o.j = o.i;
        while (o.j < size)
        {
            if (tab[o.i] > tab[o.j])
            {            
                tmp = tab[o.i];
                tab[o.i] = tab[o.j];
                tab[o.j] = tmp;
            }
            o.j++;
        }
        o.i++;
    }
}

void    ft_pre_sort(t_lst *stack)
{
    t_obj o = {0};
    t_data   *tmp;

    tmp = stack->a;
    ft_stack_tab(&stack);
    ft_sorting_tab(stack->stack_tab, (int) stack->size_tab);
    o.median = found_median(stack->stack_tab, (int) stack->size_tab);
    while (o.i < (int) stack->size_tab / 2)
    {
        if (tmp->content < o.median)
            ft_push_b(&stack->a, &stack->b, "pb", stack);
        else
        {
            while (tmp->content > o.median)
            {
                ft_rotate_a(&stack->a, "ra", stack);
                tmp = tmp->next;
            }
        }
        o.i++;
    }
    stack->size_tab = (size_t) ft_lstlen(&stack->a);
    ft_stack_tab(&stack); 
}