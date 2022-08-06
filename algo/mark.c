/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:14:51 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/04 17:23:44 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void find_mark(t_lst *stack, t_data *s_b)
{
    t_data  *tmp;
    
    s_b->mark = ft_lstmax(&stack->a)->content;
    tmp = stack->a;
    while (tmp->next)
    {
        if (s_b->mark < tmp->content)
            if (s_b->content > tmp->content)
                s_b->mark = tmp->content;
        tmp = tmp->next;
    }
    printf("%d\n", stack->a->mark);
}

void    setting_mark(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->b;
    while (tmp)
    {
        find_mark(stack, stack->b);
        tmp = tmp->next;
    }
    stack->b = tmp;
}