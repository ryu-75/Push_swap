/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:35:53 by nlorion           #+#    #+#             */
/*   Updated: 2022/09/02 14:55:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	radix_sort(t_data **stack_a, t_data **stack_b)
{
	int		size;
	int		val;
	t_obj	o;
	t_data	*tmp;

	o.i = 0;
	size = ft_lsize(*stack_a);
	while (!ft_lst_is_sort(stack_a))
	{
		o.j = 0;
		while (o.j++ < size)
		{
			tmp = *stack_a;
			val = ((tmp->idx >> o.i));
			if ((val & 1) == 1)
				ft_rotate(stack_a, "a");
			else
				ft_push_b(stack_a, stack_b);
		}
		while (ft_lsize(*stack_b) > 0)
			ft_push_a(stack_b, stack_a);
		o.i++;
	}
}
