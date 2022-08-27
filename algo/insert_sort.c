/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:43:08 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/27 14:21:35 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int push_finder(t_data **s_a, t_data **s_b)
{
    int small;
    
    ft_push_b(s_a, s_b);
    if (s_a)
        small = ft_lstmin(s_a)->content;
    return (small);
}

void    ra_or_rra(t_data **stack, int size, int pos)
{
    int low_pos;
    
    low_pos = size - pos;
    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            ft_rotate(stack, "ra");
            pos--;
        }
    }
    else if (pos > size / 2)
        while (low_pos > 0)
    {
        ft_rrotate(stack, "rra");
        low_pos--;
    }
}

void    insert_sort(t_data **s_a, t_data **s_b)
{
    int low_val;
    int size;
    int pos;
    t_data  *t_a;
    
    t_a = *s_a;
    if (ft_lst_is_sort(s_a))
        return ;
    if (t_a)
    {
        size = ft_lsize(*s_a);
        low_val = ft_lstmin(&t_a)->content;
        pos = small_id_finder(s_a, low_val);
        ra_or_rra(s_a, size, pos);
        ft_push_b(s_a, s_b);
    }
}

void    insert_sort2(t_data **s_a, t_data **s_b)
{
    t_data  *t_a;
    int size;
    
    t_a = *s_a;
    size = ft_lsize(*s_a);
    while (size > 0)
    {
        if (t_a->content)
            insert_sort(s_a, s_b);
        size--;
    }
    (*s_b)->size = ft_lsize(*s_b);
}

void    insert_sort3(t_data **s_a, t_data **s_b)
{
    int size_b;

    size_b = ft_lsize(*s_b);
    while (size_b > 0)
    {
        if ((*s_b)->content < (*s_a)->content)
            ft_push_a(s_b, s_a);
        size_b--;
    }
}