/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:36:59 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/29 16:51:41 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap the first element with the second one
void	ft_swap(t_data **stack, char *s)
{
	t_data	*tmp;

	tmp = NULL;
	if (!(*stack) || !stack)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	*stack = tmp;
	if (*s == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

// Push the first element from stack _a to stack_b
void	ft_push_a(t_data **b, t_data **a)
{
	t_data	*tmp;

	tmp = (*b);
	if (b)
	{
		(*b) = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}

// Push the first element from stack _b to stack_a
void	ft_push_b(t_data **a, t_data **b)
{
	t_data	*tmp;

	tmp = (*a);
	if (a)
	{
		(*a) = tmp->next;
		tmp->next = (*b);
		(*b) = tmp;
	}
	ft_putstr_fd("pb\n", 1);
}

// Shift up all element at the top by 1 of stack_a
// The first element begin the last
void	ft_rotate(t_data **stack, char *s)
{
	t_data	*tmp;

	tmp = *stack;
	(*stack) = (*stack)->next;
	ft_lstadd_back_value(stack, tmp);
	tmp->next = NULL;
	if (*s == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

// Shift up all element at the top by 1 of stack_b
// The last element begin the first one
void	ft_rrotate(t_data **stack, char *s)
{
	t_data	*tmp;
	t_data	*new;

	if ((*stack) && (*stack)->next)
	{
		tmp = (*stack);
		while ((*stack)->next->next)
			(*stack) = (*stack)->next;
		new = (*stack)->next;
		(*stack)->next = NULL;
		new->next = tmp;
		(*stack) = new;
		if (*s == 'a')
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("rrb\n", 1);
	}
}
