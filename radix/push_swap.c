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
    printf("stack a\n");
    while ((*stack)->a)
    {
        printf("\t%d\t\n", (*stack)->a->content);
        (*stack)->a = (*stack)->a->next;
    }
    write(1, "\n", 1);
    printf("stack b\n");
    while ((*stack)->b)
    {
        printf("\t%d\t\n", (*stack)->b->content);
        (*stack)->b = (*stack)->b->next;
    }
}

int main(int ac, char **av)
{
    t_lst   *stack_a;
    t_lst   *stack_b;

    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    stack_b = NULL;
    int idx = ft_set_id(stack_a);
    if (ac > 1)
    {   
        radix_sort(stack_a, stack_b);
        printf("%d\n", idx);
        print_lst(&stack_a);
    }
    ft_print_op(&stack_a);
    ft_clear_stack(&stack_a->a, 0);
    // ft_clear_stack(&stack_b->b, 0);
    return (0);
}


        // if (stack_a->size_tab <= 5)
        // {    // Sort only small value less then 5
        //     ft_select_sort(&stack_a);
        //     ft_set_id(&(stack_a)->a);
        // }
        // Sort above 5 until +1000 or more
/**
 *  Trouver la plus petite valeur qui est le plus proche de la stack->content dans la 1er et 2eme moitie de la stack
 *  Une fois trouve, comparer ces deux valeurs entre elle, si le coup est plus faible, envoyer la valeur en haut de la stack puis push_b
 *  Repeter l action jusqu a que la stack soit vite
 *  Ensuite trouver la valeur la plus grande dans la stack, meme principe, trouver le coup le plus faible est envoyer tous les chiffres dans la stack A
 *  
 *  Possible contrainte : chunck la stack A 25 ou 25 si 100 ou plus
 * 
 */

/**
 *  Si radix :
 *              - Stocker les valeurs dans un tableau.
 *              - On trie ce tableau
 *              - 
 * 
 */