/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:28:21 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 17:03:43 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if stack is already sort
int	ft_lst_is_sort(t_data **stack)
{
	t_data	*tmp_1;
	t_data	*tmp_2;

	tmp_1 = (*stack);
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		while (tmp_2)
		{
			if (tmp_1->content > tmp_2->content)
				return (0);
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (1);
}
