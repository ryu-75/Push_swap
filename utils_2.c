/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:46:54 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/19 11:46:54 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int ft_lstlen(t_lst **stack)
{
    t_obj o = {0};

    while ((*stack)->a)
    {
        (*stack)->size_a = o.i++;
        (*stack)->a = (*stack)->a->next;
    }
    return (o.i);
}