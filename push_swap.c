/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/14 22:58:48 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    print_lst(t_data **stack)
{
    if (!stack || !(*stack))
        return ;
    while ((*stack) != NULL)
    {
        printf("%d\n", (*stack)->content);
        (*stack) = (*stack)->next;
    }
}

int main(int ac, char **av)
{
    t_data  *a;
    int smallest;
    a = convert_av(&a, av);
    // print_lst(&a);
    ft_min_sorting(&a);
    // print_lst(&a);
    if (ac > 1)
        print_lst(&a);

        // printf("----- STACK A -----\n\n");
        // while (a)
        // {
        //     printf("\t%d\n\n", a->content);
        //     a = a->next;
        // }
        // printf("----- STACK B -----\t\n\n");
        // while (b)
        // {
        //     printf("\t%d\n\n", b->content);
        //     b = b->next;
        // }
    return (0);
}