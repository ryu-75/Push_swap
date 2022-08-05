/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:14:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/05 15:08:21 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void find_mark(t_lst *stack, t_data *s_b)
{
    t_data  *tmp;
    
    s_b->leader = ft_lstmax(&stack->a)->content;
    tmp = stack->a;
    while (tmp->next)
    {
        if (s_b->leader < stack->a->content)
            if (s_b->content > stack->a->content)
                s_b->leader = stack->a->content;
        tmp = tmp->next;
    }
}

void    setting_mark(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->b;
    while (tmp->next)
    {
        find_mark(stack, tmp);
        tmp = tmp->next;
    }
    stack->a = tmp;
}