/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:37 by nlorion           #+#    #+#             */
/*   Updated: 2022/09/03 19:35:28 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Add new node
t_data	*add_newlst(t_data *new, int el)
{
	if (!new)
		new = malloc(sizeof(t_data));
	new->content = el;
	new->idx = -1;
	new->next = NULL;
	return (new);
}

// Add a new node at the end of list
void	ft_lstadd_back_value(t_data **lst, t_data *new)
{
	t_data	*last;

	last = *lst;
	if (!lst || !new)
		return ;
	if (!last)
	{
		(*lst) = new;
		return ;
	}
	else
	{	
		while (last->next)
			last = last->next;
	}
	last->next = new;
}

// Delete one element only
void	ft_lstdel(t_data *stack, void (*del)(void *))
{
	if (!del)
		return ;
	if (stack)
		(*del)(stack);
}

// Clear list completely
void	ft_clear_stack(t_data **stack, void (*del)(void *))
{
	t_data	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		ft_lstdel(*stack, del);
		*stack = tmp;
	}
	*stack = NULL;
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
