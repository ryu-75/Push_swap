/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:14:51 by nlorion           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/04 17:23:44 by nlorion          ###   ########.fr       */
=======
/*   Updated: 2022/08/05 15:08:21 by nlorion          ###   ########.fr       */
>>>>>>> d2e5d7cf264578819d49de9f1a9a34f388878100
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
<<<<<<< HEAD
        if (s_b->mark < tmp->content)
            if (s_b->content > tmp->content)
                s_b->mark = tmp->content;
        tmp = tmp->next;
    }
    printf("%d\n", stack->a->mark);
=======
        if (s_b->leader < stack->a->content)
            if (s_b->content > stack->a->content)
                s_b->leader = stack->a->content;
        tmp = tmp->next;
    }
>>>>>>> d2e5d7cf264578819d49de9f1a9a34f388878100
}

void    setting_mark(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->b;
    while (tmp->next)
    {
<<<<<<< HEAD
        find_mark(stack, stack->b);
=======
        find_mark(stack, tmp);
>>>>>>> d2e5d7cf264578819d49de9f1a9a34f388878100
        tmp = tmp->next;
    }
    stack->a = tmp;
}