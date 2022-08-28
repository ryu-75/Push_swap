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

t_data	*ft_lst_last(t_data **stack)
{
	if (!(*stack))
		return (NULL);
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	return (*stack);
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
