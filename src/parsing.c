/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/09/04 14:44:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if av contain no double and have only digit
// Return an error if none condition is complete

static int	check_value(char **av)
{
	t_obj	o;

	o.i = 1;
	while (av[o.i])
	{
		if ((have_num(av[o.i]) == 0
				|| is_num(av[o.i]) == 0))
			return (0);
		o.i++;
	}
	return (1);
}

static int	check_no_int(char **av)
{
	t_obj	o;

	o.i = 1;
	while (av[o.i])
	{
		o.j = 0;
		while (av[o.i][o.j])
		{
			if ((av[o.i][o.j] < '0' || av[o.i][o.j] > '9')
				&& av[o.i][o.j] != '-')
				return (0);
			if (av[o.i][o.j] == '-'
				&& (av[o.i][o.j + 1] < '0' || av[o.i][o.j + 1] > '9'))
				return (0);
			o.j++;
		}
		o.i++;
	}
	return (1);
}

static int	check_arg(char **av)
{
	t_obj	o;	

	o.i = 1;
	while (av[o.i])
	{
		if (ft_strcmp(av[o.i], "") || ft_isalpha(*av[o.i]))
			return (0);
		o.i++;
	}
	return (1);
}

static int	ft_check_double(t_data **stack, int num)
{
	t_data	*tmp;

	tmp = (*stack);
	while (tmp->next)
	{
		if (tmp->content == num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Convert each av to integer and stack it into an int array
t_data	*convert_av(t_data **stack, char **av)
{
	t_obj	o;
	t_data	*tmp;
	int		num;

	if (!stack && !*stack)
		stack = malloc(sizeof(t_data));
	tmp = *stack;
	if (check_arg(av) == 1)
	{
		o.i = 1;
		while (av[o.i])
		{
			num = ft_atols(av[o.i]);
			ft_lstadd_back_value(stack, add_newlst(tmp, ft_atols(av[o.i++])));
			if ((!ft_check_double(stack, num) && check_value(av))
				|| !check_no_int(av))
				ft_error(stack, EXIT_FAILURE);
		}
	}
	else
		ft_error(stack, EXIT_FAILURE);
	return (*stack);
}
