/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:05:00 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/19 23:18:36 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Found min value and stack it
t_data	*ft_lstmin(t_data **stack)
{
    t_data  *tmp;
    t_data	*min;

    tmp = (*stack);
    min = tmp;
    while (tmp)
    {
        if (tmp->content < min->content)
            min = tmp;
        tmp = tmp->next;
    }
	return (min);
}

// Found max value and stack it
t_data	*ft_lstmax(t_data **stack)
{
	t_data	*tmp;
	t_data	*max;

	tmp = (*stack);
	max = tmp;
	while (tmp)
	{
		if (tmp->content > max->content)
		{
			max = tmp;
			max->max = tmp->content;
		}
		tmp = tmp->next;
	}
	return (max);
}

int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    while (ft_lstmin(stack)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->pos);
}

// Found the largest value in stack B
int ft_largest_value(t_data **stack)
{
    t_data  *tmp;

    tmp = *stack;
    while (ft_lstmax(stack)->content != tmp->content)
        tmp = tmp->next;
    return (tmp->pos);
}