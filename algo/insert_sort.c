/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:43:08 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/09 13:49:52 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int push_finder(t_lst *s_a, t_lst *s_b)
{
    int small;
    
    ft_push_b(&s_a->a, &s_b->b, "pb", s_a);
    if (s_a)
        small = ft_lstmin(&s_a->a)->content;
    return (small);
}

void    ra_or_rra(t_lst *stack, int size, int pos)
{
    int low_pos;
    
    low_pos = size - pos;
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            ft_rotate_a(&stack->a, "ra", stack);
            pos--;
        }
    }
    else if (pos > size / 2)
        while (low_pos > 0)
    {
        ft_rrotate_a(&stack->a, "rra", stack);
        low_pos--;
    }
}

void    insert_sort(t_lst *s_a, t_lst *s_b)
{
    int low_val;
    int size;
    int pos;
    t_data  *t_a;
    
    t_a = s_a->a;
    if (ft_lst_is_sort(&s_a->a))
        return ;
    if (t_a)
    {
        size = ft_lsize(s_a->a);
        low_val = ft_lstmin(&t_a)->content;
        pos = small_id_finder(s_a->a, low_val);
        ra_or_rra(s_a, size, pos);
        ft_push_b(&s_a->a, &s_b->b, "pb", s_a);
    }
}

void    insert_sort2(t_lst *s_a, t_lst *s_b)
{
    t_data  *t_a;
    int size;
    
    t_a = s_a->a;
    size = ft_lsize(t_a);
    while (size > 0)
    {
        if (t_a->content)
            insert_sort(s_a, s_b);
        size--;
    }
    s_b->size_b = ft_lsize(s_b->b);
}

void    insert_sort3(t_lst *s_a, t_lst *s_b)
{
    t_data  *tmp;
    int size_b;

    tmp = s_a->b;
    size_b = ft_lsize(tmp);
    while (size_b > 0)
    {
        if (s_b->b->content > s_a->a->content)
        {
            ft_push_a(&s_b->b, &s_a->a, "pa", s_a);
            ft_rotate_a(&s_a->a, "ra", s_a);
        }
        size_b--;
    }
}