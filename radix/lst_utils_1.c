/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:37 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/14 11:26:03 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Add new node
t_data  *add_newlst(t_data *new, int el)
{
    new = malloc(sizeof(t_data));
    if (!new)
        return (NULL);
    new->content = el;
    new->next = NULL;
    return (new);
}

// Add a new node at the end of list
void	ft_lstadd_back_value(t_data **lst, t_data *new)
{
	t_data	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (!last)
	{
		*lst = new;
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
void	ft_lstdel(t_data *stack, void (*del)(int))
{
	if (!del)
		return ;
	if (stack)
	{
		(*del)(stack->content);
		free(stack);
	}
}

// Clear list completely
void	ft_clear_stack(t_data **stack, void (*del)(int))
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

// Add a new element at first of list 
void	ft_addfront(t_data **stack, t_data *new)
{
	new->next = *stack;
	*stack = new;
}