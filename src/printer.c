/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:32:36 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 17:26:33 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_lst(t_data **stack)
{
	printf("\tpos\t\tstack\t\t\tidx\n");
	while ((*stack))
	{
		printf("\t%d\t|\t%d\t\t|\t%d\n",
			(*stack)->pos, (*stack)->content, (*stack)->idx);
		(*stack) = (*stack)->next;
	}
	write (1, "\n", 1);
}
