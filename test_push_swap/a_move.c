/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:36:59 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/08 22:47:11 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap_a(t_data **stack_a)
{
    t_data  *tmp;

    tmp = NULL;
    if (!(*stack_a) || !stack_a)
        return ;
    tmp = (*stack_a)->next;
    (*stack_a)->next = tmp->next;
    tmp->next = (*stack_a);
    *stack_a = tmp;
}

void    ft_push_a(t_data **stack_b, t_data **stack_a)
{
    t_data  *tmp;
    tmp = NULL;
    if (!(*stack_a) || !stack_a || !(*stack_b) || !stack_b)
        return ;
    tmp = (*stack_a);
    (*stack_b)->content = tmp->content;
}

// int main(int ac, char **av)
// {
//     t_data  *stack_a;
//     t_data  *stack_b;
//     (void) ac;
    
//     stack_b = malloc(sizeof(t_data));
//     stack_a = convert_av(&stack_a, av);
//     ft_push_a(&stack_b, &stack_a);
//     while (stack_b)
//     {
//         printf("stack_b = %d\n", stack_b->content);
//         stack_b = stack_b->next;
//     }
//     return (0);
// }