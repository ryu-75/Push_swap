/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:34:23 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/05 17:10:33 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Je recupere la distance qu il y a en partant de la mediane 
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
        else if (id == size / 2)
            dist = size - id;
        else
            dist = id + 1;
    }
    return (dist);
}

int ft_comp(int id_a, int id_b, int s_a, int s_b)
{
    if ((id_a < s_a / 2 && id_b < s_b / 2) || 
        (id_a >= s_a / 2 && id_b >= s_b / 2))
        return (1);
    return (0);
}

int ft_find_cost(int id_a, int id_b, int s_a, int s_b)
{
    int cost;

    if (ft_comp(id_a, id_b, s_a, s_b) == 1)
    {
        if (find_dist(s_a, id_a) > find_dist(s_b, id_b))
            cost = find_dist(s_a, id_a);
        else 
            cost = find_dist(s_a, id_a);
    }
    else
        cost = find_dist(s_a, id_a) + find_dist(s_b, id_b) - 1;
    return (cost);
}

void    ft_cost(t_lst *stack)
{
    t_data  *tmp_a;
    t_data  *tmp_b;

    tmp_b = stack->b;
    while (tmp_b)
    {
        tmp_a = stack->a;
        while (tmp_a)
        {
            if (tmp_a->content == stack->a->max)
                stack->b->cost = ft_find_cost(stack->a->id, stack->b->id, stack->size_a, stack->size_b);
            tmp_a = tmp_a->next;
        }
        tmp_b = tmp_b->next;
    }
}