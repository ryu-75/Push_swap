/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/07 13:25:09 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if av contain no double and have only digit
// Return an error if none condition is complete
int check_arg(char **av)
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
            if (!ft_strcmp(av[o.i], av[o.j]))
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
            ft_lstadd_back_value(tmp, add_newlst(*tmp, ft_atoi(av[o.i++])));
    }
    else
        ft_error();
    return (*stack);
}

int main(int ac, char **av)
{
    t_data  *lst;
    (void) ac;
    // t_obj o = {.i = 1};
    lst = convert_av(&lst, av);
    // printf("%d\n", lst->content);
    while (lst)
    {
        printf("%d\n", lst->content);
        lst = lst->next;
    }
    return (0);
}