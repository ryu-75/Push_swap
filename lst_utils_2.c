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
int	ft_lstmax(t_data **stack)
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
			(*stack)->max = tmp->content;
		}
		tmp = tmp->next;
	}
	return ((*stack)->max);
}

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
