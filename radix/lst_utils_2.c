/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:02 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 16:18:01 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Delete the first element of list
void	ft_del_firstel(t_data **stack)
{
	t_data	*tmp;

	tmp = NULL;
	if (!stack || !(*stack))
		return ;
	tmp = (*stack);
	tmp = tmp->next;
	ft_lstdel(*stack, 0);
	(*stack) = tmp;
}

// Delete the last element of list
void	ft_del_lastel(t_data **stack)
{
	t_data	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstdel(tmp->next, 0);
	tmp->next = NULL;
}

// Return stack size
int	ft_lsize(t_data *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

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

int	found_distance(t_data **stack, int index)
{
	t_data	*tmp;
	int	distance;

	distance = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->idx == index)
			return (0);
		distance++;
		printf("%d\n", distance);
		tmp = tmp->next;
	}
	return (distance);
}