/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:22 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/23 21:13:07 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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