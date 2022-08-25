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

void    print_lst(t_data **stack)
{
    printf("\tpos\t\tstack\t\t\tcost\t\tidx\n");
    while ((*stack))
    {
        printf("\t%d\t|\t%d\t\t|\t%d\t|\t%d\t\n", (*stack)->pos, (*stack)->content, (*stack)->cost, (*stack)->idx);
        (*stack) = (*stack)->next;
    }
    write (1, "\n", 1);
}

int main(int ac, char **av)
{
    t_data  *stack_a;
    t_data  *stack_b;
    // t_obj o = {0};

    stack_a = malloc(sizeof(t_data));
    stack_a = convert_av(&stack_a, av);
    stack_a->size = ft_lsize(stack_a);
    stack_b = malloc(sizeof(t_data));
    stack_b = NULL;
    if (ac > 1)
    {   
        if (stack_a->size <= 5)
        {    // Sort only small value less then 5
            ft_select_sort(&stack_a, &stack_b);
        }
        else if (stack_a->size > 5)
        {
            ft_set_pos(&stack_a);
            index_it(&stack_a);
            ft_rrotate(&stack_a, "a", stack_a);
            // ft_pre_sort(&stack_a, &stack_b);

            // ft_set_pos(&stack_a);
            // ft_set_pos(&stack_b);
            
            // t_data  *target = ft_found_target(&stack_a, &stack_b);
            // printf("target = %d\n", target->idx);
            // printf("best = %d\n", ft_best_cost(&stack_a, &stack_b));

            // index_it(&stack_a);
            // // if (stack_b)
            // // {
            // //     ft_set_pos(&stack_b);
            // //     index_it(&stack_b);
            // // }       
        }
        // Print all stack 
        print_lst(&stack_a);
        // print_lst(&stack_b);
    }
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

/**
 *  Si radix :
 *              - Stocker les valeurs dans un tableau.
 *              - On trie ce tableau
 *              - 
 *  Revoir l affiche des operations. Changer de fonction pour l appel et la comparaison des valeurs appeler entre sa et sb par exemple
 */