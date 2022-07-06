/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/06 19:51:01 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if av contain no double and have only digit
// Return an error if none condition is complete
int check_arg(char **av)
{
    t_obj o = {0};

    while (av[o.i])
    {
        if (have_num(av[o.i]) == 0)
            return (0);
        o.i++;
    }
    o.i = 0;
    while (av[o.i])
    {
        o.j = o.i + 1;
        while (av[o.j])
        {
            if (!ft_strcmp(av[o.i], av[o.j]))
                return (0);
            o.j++;
        }
        o.i++;
    }
    return (1);
}

// Convert each av to integer and stack it into an int array
t_data  *convert_av(int ac, char **av)
{
    t_obj o = {0};
    t_data  **stack;

    stack = malloc(sizeof(t_data**));
    while (av[o.i])
    {
        if (check_arg(av) == 0)
            ft_error();
        ft_lstadd_back_value(stack, add_newlst(*stack, ft_atoi(av[o.i++])));
        printf("%d\n", (*stack)->content);
        *stack = (*stack)->next;
    }
    return (*stack);
}

// void    ft_printlst(t_data *stack_a)
// {
//     int i;

//     i = 0;
//     if (!stack_a)
//         stack_a = malloc(sizeof(t_data));
//     printf("%d\n", stack_a->content);
// }

// int main(int ac, char **av)
// {
//     t_data *lst;
//     t_obj o = {1};
  
//     lst = NULL;
//     if (ac > 1)
//     {
//         convert_av(ac, &av[o.i++]);
//     }
//     return (0);
// }