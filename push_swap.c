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

// void    push_swap(t_data *stack_a, t_data *stack_b)
// {
//     t_data  *cheap;
//     t_data  *add;
//     t_data  *b;

//     b = stack_b;
//     if (!b)
//         return ;
//     while (b)
//     {
//         ft_set_abs(&stack_a, &stack_b);
//         cheap = ft_cheap_cost(&stack_b);
//         add = ft_found_target(&stack_a, &stack_b);
//         ft_final_move(&stack_a, &stack_b, add->cost, cheap->cost);
//         ft_push_a(&stack_b, &stack_a);
//         // b = b->next;
//     }
// }

int main(int ac, char **av)
{
    t_data  *stack_a;
    t_data  *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        return (-1);
    stack_a = convert_av(&stack_a, av);
    stack_a->size = ft_lsize(stack_a);
    index_it(&stack_a);
    if (stack_a->size <= 5)
    {
        ft_select_sort(&stack_a, &stack_b);
        // ft_clear_stack(&stack_a, 0);
    }
    ft_set_pos(&stack_a);
    ft_set_pos(&stack_b);
    ft_set_cost(&stack_a);
    ft_set_cost(&stack_b);
    radix_sort(&stack_a, &stack_b);
    print_lst(&stack_a);
    print_lst(&stack_b);
    // ft_clear_stack(&stack_a, 0);
    // ft_clear_stack(&stack_b, 0);
    return (0);
}