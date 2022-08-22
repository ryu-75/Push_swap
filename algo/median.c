/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:27:10 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/22 22:46:43 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int found_median(t_lst **stack)
{
    t_data  *tmp;
    int median;
    int size;

    tmp = (*stack)->a;
    size = ft_lsize(tmp);
    while (tmp)
    {
        if (tmp->idx == size / 3)
            median = (*stack)->a->idx;
        tmp = tmp->next;
    }
    return (median);
}