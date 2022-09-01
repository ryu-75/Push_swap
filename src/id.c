/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:35:27 by nlorion           #+#    #+#             */
/*   Updated: 2022/09/01 21:27:23 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index_max(t_data **stack)
{
	t_data	*max_value;
	t_data	*max;
	t_obj	o = {0};
	
	max_value = (*stack);
	max = (*stack);
	while (max_value && o.i < ft_lsize(*stack))
	{
		if (max_value->content > max->idx - 1)
			max->idx = o.i;
		o.i++;
	}
	return (max->idx);
}

t_data	*hash_list(t_data **stack)
{
	int		min_found;
	t_data	*tmp;
	t_data	*min;

	min = NULL;
	min_found = 0;
	tmp = *stack;
	if (tmp)
	{
		while (tmp)
		{
			if ((tmp->idx == -1) && (!min_found || tmp->content < min->content))
			{
				min = tmp;
				min_found = 1;
			}
			tmp = tmp->next;
		}
	}
	return (min);
}

void	index_it(t_data **stack)
{
	t_data	*tmp;
	int		index;

	tmp = hash_list(stack);
	index = 0;
	while (tmp)
	{
		tmp->idx = index++;
		tmp = hash_list(stack);
	}
}
