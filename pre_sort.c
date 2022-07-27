/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/27 13:15:51 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void ft_stack_tab(t_lst **stack)
{
    t_obj o = {0};
    t_lst   *tmp;
    int len;

    len = (*stack)->a->size;
    tmp = (*stack);
    (*stack)->stack_tab = malloc(sizeof(int) * len);
    if (!(*stack)->stack_tab)
        free((*stack)->stack_tab);
    while (tmp->a)
    {
        tmp->stack_tab[o.i] = tmp->a->content;
        o.i++;
        tmp->a = tmp->a->next;
    }
    // o.i = 0;
    // while (o.i < len)
    //     printf("index = %d\n", (*stack)->stack_tab[o.i++]);
}

int  found_median(int size)
{   
    int median;
    
    if (size % 2 == 0)
        median = (size / 2) + 1;
    else
        median = (size + 1) / 2;
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
    o.i = 0;
    while (o.i < size)
        printf("%d\n", tab[o.i++]);
}

void    ft_pre_sort(t_lst **stack)
{
    t_obj o = {0};
    int median; 
    int len;

    len = (*stack)->a->size;
    median = found_median(len);
    ft_stack_tab(stack);
    ft_sorting_tab((*stack)->stack_tab, len);
    while (o.i < len)
    {
        if (median > 3)
            ft_push_b(&(*stack)->a, &(*stack)->b, "pb", (*stack));
        else
            ft_rotate_a(&(*stack)->a, "ra", (*stack));
        o.i++;
    }
    (*stack)->a->size = ft_lsize(*stack);
    ft_stack_tab(stack);
}

/*
    J'ai maintenant récupérée tous mes int dans mon tableau.
    Je veux maintenant renvoyer les int 
*/
/*  SORT    NOT SORT
------------------------
    -68     4
    -12     5
    1       78
    4       1
    5       94
    7       -68
    32      -12  <----------- MEDIAN 
    42      7
    78      32
    93      42
    94      93
    102     102
*/

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

void    send_biggest(t_lst **stack)
{
    t_lst   *tmp;

    tmp = (*stack);
    while (tmp->a->next)
    {
        if (tmp->a->id == 0)
        {
            ft_rrotate_a(&(*stack)->a, "rra", (*stack));
        }
        tmp->a = tmp->a->next;
    }
}

void    scan_all_stack(t_lst **stack)
{
    int hold_first;
    int hold_second;
    t_lst   *tmp;

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