/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:27 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/03 13:44:29 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Retrieve index of each value in stack 
int ft_set_id(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = (*stack);
	while (pos && pos->next)
    {
        pos->id = o.i++;
        pos = pos->next;
	}
	pos->id = o.i;
    return (o.i + 1);
}