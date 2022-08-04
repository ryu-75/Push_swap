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
        printf("\t%d\t|\t%d\t|\t%d\t\n", (*stack)->a->id, (*stack)->a->content, (*stack)->a->cost);
        (*stack)->a = (*stack)->a->next;
    }
    write(1, "\n", 1);
    printf("\tpos\t\tstack b\t\n");
    while ((*stack)->b)
    {
        printf("\t%d\t|\t%d\t|\t%d\t\n", (*stack)->b->id, (*stack)->b->content, (*stack)->b->cost);
        (*stack)->b = (*stack)->b->next;
    }
}

int main(int ac, char **av)
{
    t_lst   *stack_a;
    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    stack_a->size_a = ft_lsize(stack_a->a);
    stack_a->size_b = ft_lsize(stack_a->b);     
    if (ac > 1)
    {       
        stack_a->size_tab = ft_tablen(av);
        if (stack_a->size_tab <= 5)
            ft_select_sort(&stack_a);
        else
        {
            ft_pre_sort(stack_a);
            // Setting ID
            if (stack_a->a && stack_a->b)
            {
                ft_set_id(&(stack_a)->a);     
                ft_set_id(&(stack_a)->b);
            }
            else if (stack_a->a)
                ft_set_id(&(stack_a)->a);
            else
                ft_set_id(&(stack_a)->b);
        }
        print_lst(&stack_a);
    }
    ft_print_op(&stack_a);
    return (0);
}

/*
    Adapter l'algo de maniere a ranger toutes les valeurs du plus grand au plus petit
    Optimiser egalement
    Voir si :
        * Trouver la valeur la plus grande dans stack b
        * La remonter a l index 0
        * Push dans A
        * Repeter l action
*/