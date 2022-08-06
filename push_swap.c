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
<<<<<<< HEAD
    stack_a->size_b = ft_lsize(stack_a->b);
    setting_mark(stack_a);
=======
    ft_lstmax(&stack_a->a);
>>>>>>> d2e5d7cf264578819d49de9f1a9a34f388878100
    if (ac > 1)
    {   
        // Register tab lenght
        stack_a->size_tab = ft_tablen(av);
        if (stack_a->size_tab <= 5)
        {
            // Sort only small value less then 5
            ft_select_sort(&stack_a);
        }
        else
        {
<<<<<<< HEAD
            ft_pre_sort(stack_a);
            ft_push_a(&stack_a->b, &stack_a->a, "pa", stack_a);
            ft_push_a(&stack_a->b, &stack_a->a, "pa", stack_a);
            ft_push_a(&stack_a->b, &stack_a->a, "pa", stack_a);
            ft_push_a(&stack_a->b, &stack_a->a, "pa", stack_a);
            // ft_push_a(&stack_a->b, &stack_a->a, "pa", stack_a);
            ft_cost(stack_a);
            printf("%d\n", stack_a->b->cost);
=======
>>>>>>> d2e5d7cf264578819d49de9f1a9a34f388878100
            // Setting ID
            ft_pre_sort(stack_a);
            stack_a->size_a = ft_lsize(stack_a->a);
            stack_a->size_b = ft_lsize(stack_a->b);
            if (stack_a->a && stack_a->b)
            {
                ft_set_id(&(stack_a)->a);
                ft_set_id(&(stack_a)->b);
            }
            stack_id_a(stack_a);
            stack_id_b(stack_a);
            ft_cost(stack_a);
            printf("s_a = %d\ns_b = %d\nid a = %d\nid b = %d\n", stack_a->size_a, stack_a->size_b, stack_a->a->id, stack_a->b->id);
            if (stack_a->a && stack_a->b)
            {
                ft_set_id(&(stack_a)->a);
                ft_set_id(&(stack_a)->b);
            }
        }
        // Sort above 5 until 500 or more
        print_lst(&stack_a);
    }
    ft_print_op(&stack_a);

    return (0);
}

/**
 * Checker les valeurs par id
 * Trouver la longueur la plus longue deja trie et push le reste dans B en meme temps
 * Creer un tableau d int a deux dimension qui va stocker le nombre de coup de chaque id
 * Calculer la difference pour recuperer la valeur absolue qui correspond au nombre de coup necessaire
 * 
 */


/*
    Adapter l'algo de maniere a ranger toutes les valeurs du plus grand au plus petit
    Optimiser egalement
    Voir si :
        * Trouver la valeur la plus grande dans stack b
        * La remonter a l index 0
        * Push dans A
        * Repeter l action
*/