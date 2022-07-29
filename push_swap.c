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
        printf("\t%d\t|\t%d\t|\t%d\t\n", (*stack)->a->pos, (*stack)->a->content, (*stack)->a->cost);
        (*stack)->a = (*stack)->a->next;
    }
    write(1, "\n", 1);
    printf("\tpos\t\tstack b\t\n");
    while ((*stack)->b)
    {
        printf("\t%d\t|\t%d\t|\t%d\t\n", (*stack)->b->pos, (*stack)->b->content, (*stack)->b->cost);
        (*stack)->b = (*stack)->b->next;
    }
}

int main(int ac, char **av)
{
    t_lst   *stack_a;

    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    if (ac > 1)
    {       
        stack_a->size_tab = ft_tablen(av);
        ft_cost(stack_a);
        if (stack_a->size_tab <= 5)
            ft_select_sort(&stack_a);
        // else if (stack_a->size_tab > 5)
        print_lst(&stack_a);
    }
    ft_print_op(&stack_a);
    return (0);
}

/*
    Récupérer :
        * L'id de la stack
        * La taille de la stack A et B
        * Le nombre de coût nécessaire pour ra ou rra
        * La taille totale de la stack A
    
    Revoir chaque fonction puis trouver une solution pour appliquer chaque valeur 
    à leur variable attitrée.

*/