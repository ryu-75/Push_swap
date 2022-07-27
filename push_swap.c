/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 17:21:25 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    print_lst(t_lst **stack)
{
    printf("\tpos\t\tstack a\t\n");
    while ((*stack)->a)
    {
        printf("\t%d\t|\t%d\t\n", (*stack)->a->pos, (*stack)->b->content);
        (*stack)->a = (*stack)->a->next;
    }
}

int main(int ac, char **av)
{
    t_lst   *stack_a;
    (void) ac;

    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    ft_pre_sort(&stack_a);
    if (ac > 1)
        print_lst(&stack_a);
    // ft_print_op(&stack_a);
    return (0);
}