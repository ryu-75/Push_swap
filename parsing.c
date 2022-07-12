/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/12 11:54:11 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Return len tab 
static size_t ft_tablen(char **av, int count)
{   
    count = 0;
    if (!av)
        return (0);
    while (av[count])
        count++;
    count--;
    return (count);
}

// Check if av contain no double and have only digit
// Return an error if none condition is complete
static int check_arg(char **av)
{
    t_obj o = {.i = 1, .j = 1};

    while (av[o.i])
    {
        if (have_num(av[o.i]) == 0)
            return (0);
        o.i++;
    }
    o.i = 1;
    while (av[o.i])
    {
        o.j = o.i + 1;
        while (av[o.j])
        {
            if (ft_strcmp(av[o.i], av[o.j]) == 0)
                return (0);
            o.j++;
        }
        o.i++;
    }
    return (1);
}

// Convert each av to integer and stack it into an int array
t_data  *convert_av(t_data **stack, char **av)
{
    t_obj o = {.i = 1};
    t_data  **tmp;

    stack = malloc(sizeof(t_data**));
    tmp = NULL;
    tmp = stack;
    if (check_arg(av) == 1)
    {
        while (av[o.i])
        {
            ft_lstadd_back_value(tmp, add_newlst(*tmp, ft_convert_value(av[o.i++])));
            o.len = ft_tablen(av, o.i);
        }
        (*stack)->size = o.len; 
    }
    else
        ft_error();
    return (*stack);
}

int main(int ac, char **av)
{
    t_data  *stack;

    stack = convert_av(&stack, av);
    if (ac > 1)
    {
        printf("%ld\n", stack->size);
    }
    return (0);
}