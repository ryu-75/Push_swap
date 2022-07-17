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
static int check_arg(char **av)
{
    t_obj o = {.i = 1, .j = 1};

    while (av[o.i])
    {
        if (have_num(av[o.i]) == 0)
            return (0);
        o.i++;
    }
    // o.i = 1;
    // while (av[o.i])
    // {
    //     o.j = o.i + 1;
    //     while (av[o.j])
    //     {
    //         if (ft_strcmp(av[o.i], av[o.j]) == 0)
    //             return (0);
    //         o.j++;
    //     }
    //     o.i++;
    // }
    return (1);
}

int ft_check_double(int *tab, int index, int num)
{
    t_obj o = {0};

    if (!tab)
        return (0);
    while (tab[o.i] < index)
    {
        if (tab[o.i] == num)
            return (0);
        o.i++;
    }
    return (1);
}

// Corriger la gestion d erreurs des doublons

// Convert each av to integer and stack it into an int array
t_data  *convert_av(t_data **stack, char **av)
{
    t_obj o = {.i = 1};
    t_data  **tmp;
    int nb;
    int *tab;

    tab = NULL;
    tab = malloc(sizeof(int) * ft_tablen(tab) + 1);
    stack = malloc(sizeof(t_data**));
    tmp = stack;
    if (check_arg(av) == 1)
    {
        while (av[o.i])
        {
            nb = ft_convert_value(av[o.i]);
            *tab = nb++;
            if (ft_check_double(tab, o.i, nb) == 1)
                ft_lstadd_back_value(tmp, add_newlst(*tmp, ft_convert_value(av[o.i++])));
            else
                ft_error();
        }
    }
    else
        ft_error();
    free(tab);
    return (*stack);
}