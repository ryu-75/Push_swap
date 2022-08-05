/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:14:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/05 12:19:51 by nlorion          ###   ########.fr       */
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
        if (s_b->leader < tmp->content)
            if (s_b->content > tmp->content)
                s_b->leader = tmp->content;
        tmp = tmp->next;
    }
    // printf("%d\n", stack->b->leader);
}

void    setting_mark(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->a;
    while (tmp)
    {
        find_mark(stack, stack->a);
        tmp = tmp->next;
    }
    stack->a = tmp;
}