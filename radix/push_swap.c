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

// static void ft_push_swap(t_data **stack_a, t_data **stack_b)
// {
//     int id;

//     id = ft_set_pos(stack_a);
//     if (id <= 5)
//         ft_small_sort(stack_a, stack_b);
// }

void    print_lst(t_data **a, t_data **b)
{
    printf("\tpos\t\tstack a\t\tid\n\n");
    while ((*a))
    {
        printf("\t%d\t\t%d\t\t%d\t\n", (*a)->pos, (*a)->content, (*a)->idx);
        (*a) = (*a)->next;
    }
    write(1, "\n", 1);
    printf("\tpos\t\tstack b\t\tid\n\n");
    while ((*b))
    {
        printf("\t%d\t\t%d\t\t%d\t\n", (*b)->pos, (*b)->content, (*b)->idx);
        (*b) = (*b)->next;
    }
}

int main(int ac, char **av)
{
    t_data  *stack_a;
    t_data  *stack_b;

    stack_a = malloc(sizeof(t_data));
    stack_a = convert_av(&(stack_a), av);
    stack_b = NULL;
    stack_b = malloc(sizeof(t_data));
    if (ac > 1)
    {
        // radix_sort(&stack_a, &stack_b);
        index_it(&stack_a);
        ft_set_pos(&stack_a);
        ft_get_min(&stack_a, -1);
        ft_move_3(&stack_a);
        // ft_move_4(&stack_a, &stack_b);
        ft_set_pos(&stack_a);
        index_it(&stack_a);
        print_lst(&stack_a, &stack_b);
    }
    // ft_print_op(&stack_a);
    ft_clear_stack(&stack_a, 0);
    ft_clear_stack(&stack_b, 0);
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
 *  Recuperer la distance : si l index est = index return ; on compte la distance qu il y a entre t_data->index et l index donne
 */