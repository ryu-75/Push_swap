/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:02:39 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/28 23:25:16 by nlorion          ###   ########.fr       */
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
        pos->pos = o.i;
        o.i++;
        pos = pos->next;
	}
    return (o.i + 1);
}