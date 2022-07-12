/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:31 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/12 10:21:58 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Swap the first element with the second one
void    ft_swap_b(t_data **stack_b)
{
    t_data  *tmp;

    tmp = NULL;
    if (!(*stack_b) || !stack_b)
        return ;
    tmp = (*stack_b)->next;
    (*stack_b)->next = tmp->next;
    tmp->next = (*stack_b);
    *stack_b = tmp;
}

// Push the first element from stack _b to stack_a
void    ft_push_b(t_data **stack_a, t_data **stack_b)
{
    t_data  *tmp;
    tmp = NULL;
    if (!(*stack_a) || !stack_a || !(*stack_b) || !stack_b)
        return ;
    tmp = (*stack_b);
    (*stack_a)->content = tmp->content;
}

// Shift up all element at the top by 1 of stack_b
// The first element begin the last
void    ft_rotate_b(t_data **stack_b)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_b))
        return ;
    tmp = (*stack_b);
    while (tmp->content < 1)
        tmp = tmp->next;
    ft_lstadd_back_value(stack_b, add_newlst((*stack_b), tmp->content));
    ft_del_firstel(stack_b);
}

// Shift up all element at the top by 1 of stack_a
// The last element begin the first one
void    ft_rrotate_b(t_data **stack_b)
{
    t_data  *tmp;
    
    tmp = NULL;
    if (!(*stack_b))
        return ;
    tmp = (*stack_b);
    while (tmp->next)
        tmp = tmp->next;
    ft_addfront(stack_b, add_newlst((*stack_b), tmp->content));
    ft_del_lastel(stack_b);
}

// int main(int ac, char **av)
// {
//     t_data  *stack_a;
//     (void) ac;

//     stack_a = convert_av(&stack_a, av);
//     ft_rotate_b(&stack_a);
//     while (stack_a)
//     {
//         printf("%d\n", stack_a->content);
//         stack_a = stack_a->next;
//     }
//     return (0);
// }