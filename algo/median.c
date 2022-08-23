/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:27:10 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/23 19:01:57 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int found_median(t_data **stack)
{
    t_data  *tmp;
    int median;
    int size;

    tmp = (*stack);
    size = ft_set_pos(stack);
    index_it(stack);
    while (tmp)
    {
        if (tmp->idx == size / 3)
            median = tmp->idx;
        tmp = tmp->next;
    }
    printf("%d\n", median);
    return (median);
}

