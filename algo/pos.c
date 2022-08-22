/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:02:39 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/22 22:11:12 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Retrieve pos of each value in stack 
int ft_set_pos(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = (*stack);
	while (pos && pos->next)
    {
        pos->pos = o.i++;
        pos = pos->next;
	}
	pos->pos = o.i;
    return (o.i + 1);
}