/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:27 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/16 18:48:49 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Retrieve index of each value in stack 
int ft_set_id(t_lst *stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = stack->a;
	while (pos && pos->next)
    {
        pos->idx = o.i++;
        pos = pos->next;
	}
	pos->idx = o.i;
    return (o.i + 1);
}