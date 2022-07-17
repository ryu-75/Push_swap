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
t_data	*ft_lstmax(t_data **stack)
{
	t_data	*tmp;
	t_data	*max;

	tmp = (*stack);
	max = tmp;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

// Retrieve index of each value in stack 
int ft_set_id(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = (*stack);
	while (pos && pos->next)
    {
        pos->id = o.i++;
        pos = pos->next;
	}
    return (o.i + 1);
}