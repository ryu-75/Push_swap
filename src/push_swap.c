/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 16:54:32 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (-1);
	stack_a = convert_av(&stack_a, av);
	stack_a->size = ft_lsize(stack_a);
	index_it(&stack_a);
	if (stack_a->size <= 5)
	{
		ft_select_sort(&stack_a, &stack_b);
		ft_clear_stack(&stack_a, 0);
	}
	ft_set_pos(&stack_a);
	ft_set_pos(&stack_b);
	radix_sort(&stack_a, &stack_b);
	ft_clear_stack(&stack_a, 0);
	ft_clear_stack(&stack_b, 0);
	return (0);
}