/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:02 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/14 22:09:16 by nlorion          ###   ########.fr       */
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
int	ft_lstmin(t_data **stack)
{
    t_data  *tmp;
    int min;

    if (!stack || !(*stack))
        return (0);
    tmp = (*stack);
    min = tmp->content;
    while (tmp)
    {
        if (min > tmp->content)
            min = tmp->content;
        tmp = tmp->next;
    }
	(*stack)->min = min;
	return (min);
}

// Found max value and stack it
int	ft_lstmax(t_data **stack)
{
	t_data	*tmp;
	int	max;

	if (!stack || !(*stack))
		return (0);
	tmp = (*stack);
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	(*stack)->max = max;
	return (max);
}

// Retrieve index of each value in stack 
int ft_position(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = malloc(sizeof(t_data));
    if (!stack || !(*stack) || !pos)
        return (0);
    pos = (*stack);
    while (pos && pos->next)
    {
        pos->id = o.i++;
        pos = pos->next;
    }
    pos->id = o.i;
    return (o.i + 1);
}