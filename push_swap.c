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
    printf("\tpos\t\tstack\t\t\tcost\t\tidx\t\tabs\n");
    while ((*stack))
    {
        printf("\t%d\t|\t%d\t\t|\t%d\t|\t%d\t|\t%d\t\n", (*stack)->pos, (*stack)->content, (*stack)->cost, (*stack)->idx, (*stack)->abs);
        (*stack) = (*stack)->next;
    }
    write (1, "\n", 1);
}

void    push_swap(t_data **stack_a, t_data **stack_b)
{
    t_data  *head_b;
    // t_data  *cheap;
    // t_data  *add;

    head_b = *stack_b;
    if (!head_b)
        return ;
    while (head_b)
    {
        ft_set_pos(stack_a);
        ft_set_pos(stack_b);
        ft_set_cost(stack_a);
        ft_set_cost(stack_b);
        ft_set_abs(stack_a, stack_b);
        // ft_cheap_cost(stack_b);
        // ft_found_target(stack_a, stack_b);
        ft_final_move(stack_a, stack_b, ft_cheap_cost(stack_b)->cost, ft_found_target(stack_a, stack_b)->cost);
        // ft_push_a(stack_b, stack_a);
        head_b = head_b->next;
    }
}

int main(int ac, char **av)
{
    t_data  *stack_a;
    t_data  *stack_b;

    stack_a = malloc(sizeof(t_data));
    stack_a = convert_av(&stack_a, av);
    stack_a->size = ft_lsize(stack_a);
    stack_b = malloc(sizeof(t_data));
    stack_b = NULL;
    if (ac > 1)
    {
        index_it(&stack_a);
        if (stack_a->size <= 5)
        {    // Sort only small value less then 5
            ft_select_sort(&stack_a, &stack_b);
        }
        else if (stack_a->size > 5)
        {
            ft_pre_sort(&stack_a, &stack_b);
            push_swap(&stack_a, &stack_b);
        }
        // Print all stack 
        print_lst(&stack_a);
        print_lst(&stack_b);
    }
    return (0);
}