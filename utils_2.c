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

void    ft_lstlen(t_data **stack)
{
    t_obj o = {0};
    t_data   *tmp;

    tmp = (*stack);
    while (tmp)
    {
        tmp->pos = o.i++;
        tmp = tmp->next;
    }
}