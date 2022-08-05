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


void    found_id_max(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->a;
    while (tmp->content != ft_lstmax(&stack->a)->content)
    {
        if (ft_lstmax(&stack->a)->content)
        {
            stack->a->id = stack->a->next->id;
            tmp->id = stack->a->id;
        }
        tmp = tmp->next;
    }
    printf("%d\n", tmp->id);
}

void    found_id_min(t_lst *stack)
{
    t_data   *tmp;

    tmp = stack->a;
    while (tmp->content != ft_lstmin(&stack->a)->content)
    {
        if (ft_lstmax(&stack->a)->content)
        {
            stack->a->id = stack->a->next->id;
            tmp->id = stack->a->id;
        }
        tmp = tmp->next;
    }
    printf("%d\n", tmp->id);
}

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
    (void) ac;
    stack_a = malloc(sizeof(t_lst));
    stack_a->a = convert_av(&(stack_a)->a, av);
    // Register size of both stack 
    stack_a->size_a = ft_lsize(stack_a->a);
    stack_a->size_b = ft_lsize(stack_a->b);
    // Stack ID of min and max value
    ft_set_id(&(stack_a)->a);
    found_id_min(stack_a);
    found_id_max(stack_a);
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
            // Sort above 5 until 500 or more
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
            ft_pre_sort(stack_a);
        }
        print_lst(&stack_a);
    }
    ft_print_op(&stack_a);

    return (0);
}

/**
 * Checker les valeurs par id
 * 
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