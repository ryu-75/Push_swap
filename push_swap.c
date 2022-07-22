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
    t_lst   *stack_a;
    int dist;
    int id;
    int size;

    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    size = ft_lstlen(&stack_a);
    id = ft_set_id(&stack_a->a);
    dist = find_dist(size, id);
    if (ac > 1)
            print_lst(&stack_a->a);
    printf("dist = %d\n", dist);
    // ft_print_op(&stack_a);
    return (0);
}
/*
**  Trouver le plus petit element dans la stack A.
**  Deplacer l'element trouve em haut de la stack A.
**  Mettre cet element dans la stack B.

**  Repeter les etapes precedentes jusqu'a ce que la stack A soit vide.

**  Mettre tous les elements dans la stack A une fois que tous les elements sont du plus grands au plus petits.
*/