/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:05:00 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 17:05:02 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Found min value and stack it
t_data	*ft_lstmin(t_data **stack)
{
	t_data	*tmp;
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

// Stack pos of smallest value in stack A
int	ft_smallest_value(t_data **stack)
{
	t_data	*tmp;

	tmp = *stack;
	while (ft_lstmin(stack)->content < tmp->content)
		tmp = tmp->next;
	return (tmp->pos);
}
