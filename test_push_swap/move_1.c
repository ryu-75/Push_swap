/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:23:36 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/07 12:52:30 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data    *ft_swap_a(t_data **stack)
{
    t_data  **tmp;

    tmp = NULL;
    if (!stack)
        return (NULL);
    (*tmp)->next = (*stack);
    (*stack) = (*stack)->next;
    (*stack)->next = (*tmp)->next;
    return ((*stack));
}

void    ft_printlst(t_data **stack_a)
{
    if (!(*stack_a))
        stack_a = malloc(sizeof(t_data**));
    while (stack_a)
    {
        printf("%d\n", (*stack_a)->content);
        (*stack_a) = (*stack_a)->next;
    }
}

// int main(int ac, char **av)
// {
//     t_data *lst;
//     t_data *tmp;

//     if (ac > 1)
//     {
//         convert_av(&lst, av);
//         tmp = ft_swap_a(&lst);
//         ft_printlst(&tmp);
//     }
//     return (0);
// }