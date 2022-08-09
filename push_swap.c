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
    printf("\tpos\t\tstack a\t\tcost\t\tidx\n");
    while ((*stack)->a)
    {
        printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t\n", (*stack)->a->id, (*stack)->a->content, (*stack)->a->cost, (*stack)->a->idx);
        (*stack)->a = (*stack)->a->next;
    }
    write(1, "\n", 1);
    printf("\tpos\t\tstack b\t\tcost\t\tid\t\n");
    while ((*stack)->b)
    {
        printf("\t%d\t|\t%d\t\n", (*stack)->b->id, (*stack)->b->content);
        (*stack)->b = (*stack)->b->next;
    }
}

int main(int ac, char **av)
{
    t_lst   *stack_a;

    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    stack_a->size_a = ft_lsize(stack_a->a);
    ft_lstmax(&stack_a->a);
    if (ac > 1)
    {   
        // Register tab lenght
        stack_a->size_tab = ft_tablen(av);
        if (stack_a->size_tab <= 5)
        {    // Sort only small value less then 5
            ft_select_sort(&stack_a);
            ft_set_id(&(stack_a)->a);
        }
        else
        {
            set_cost(stack_a);
            // insert_sort2(stack_a, stack_a);
            // insert_sort3(stack_a, stack_a);
            // Set ID
            if (stack_a->a && stack_a->b)
            {
                ft_set_id(&(stack_a)->a);
                ft_set_id(&(stack_a)->b);
            }
            else
                ft_set_id(&(stack_a)->a);
        }
        // Sort above 5 until +1000 or more
        print_lst(&stack_a);
    }
    // ft_print_op(&stack_a);
    return (0);
}

/**
 *  Trouver la plus petite valeur qui est le plus proche de la stack->content dans la 1er et 2eme moitie de la stack
 *  Une fois trouve, comparer ces deux valeurs entre elle, si le coup est plus faible, envoyer la valeur en haut de la stack puis push_b
 *  Repeter l action jusqu a que la stack soit vite
 *  Ensuite trouver la valeur la plus grande dans la stack, meme principe, trouver le coup le plus faible est envoyer tous les chiffres dans la stack A
 *  
 *  Possible contrainte : chunck la stack A 25 ou 25 si 100 ou plus
 * 
 */