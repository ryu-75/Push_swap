/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:37 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/08 23:28:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data  *add_newlst(t_data *new, int el)
{
    new = malloc(sizeof(t_data));
    if (!new)
        return (NULL);
    new->content = el;
    new->next = NULL;
    return (new);
}

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

// void	ft_delete_el(t_data **stack)
// {
// 	t_data	*tmp;
// 	if (!stack)
// 		return ;
// 	tmp = (*stack);
// 	tmp = tmp->next;
// 	tmp->next = NULL;
// }

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

// Faire une fonction qui permet de supprimer seulement le première élément de la liste
void	ft_lst_el(t_data **stack, void (*del)(int))
{
	t_data	*tmp_1;
	t_data	*tmp_2;
	
	tmp_1 = (*stack);
	tmp_1 = tmp_1->next;
	//ft_clear_stack(stack, del);
}

int main(int ac, char **av)
{
    t_data  *stack;
	(void)	ac;
	
	stack = convert_av(&stack, av);
	ft_lst_el(&stack, 0);
	if (ac > 1)
	{
		while (stack)
		{
			printf("%d\n", stack->content);
			stack = stack->next;	
		}
		// while (stack)
		// {
		// 	printf("%d\n", stack->content);
		// 	stack = stack->next;	
		// }
	}
    return (0);
}