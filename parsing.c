/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 18:23:39 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Check if av contain no double and have only digit
// Return an error if none condition is complete

size_t  ft_tablen(char **av)
{
    size_t  i;
    
    i = 0;
    while (*av++)
        i++;
    i--;
    return (i);
}

static int check_arg(char **av)
{
    t_obj o = {.i = 1, .j = 1};

    while (av[o.i])
    {
        if (have_num(av[o.i]) == 0 || 
            is_num(av[o.i]) == 0)
            return (0);
        o.i++;
    }
    o.i = 1;
    while (av[o.i])
    {
        if (ft_strcmp(av[o.i], "") || ft_isalpha(*av[o.i]))
            return (0);
        o.i++;
    }
    return (1);
}

static int ft_check_double(t_data **stack, int num)
{
    t_data  *tmp;

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
t_data  *convert_av(t_data **stack, char **av)
{
    t_obj o = {.i = 1};
    t_data  **tmp;
    int num;

    stack = malloc(sizeof(t_data**));
    tmp = stack;
    if (check_arg(av) == 1)
    {
        while (av[o.i])
        {
            num = ft_convert_value(av[o.i]);
            ft_lstadd_back_value(tmp, add_newlst(*tmp, ft_convert_value(av[o.i++])));
            if (!ft_check_double(stack, num))
                ft_error(stack, EXIT_FAILURE);
        }
    }
    else
        ft_error(stack, EXIT_FAILURE);
    return (*stack);
}