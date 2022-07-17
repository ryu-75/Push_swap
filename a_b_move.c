/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 09:47:50 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **stack_a, t_data **stack_b, t_lst *data)
{
    ft_rrotate_a(stack_a, "rra", data);
    ft_rrotate_b(stack_b, "rrb", data);
    ft_ops("rrr", data);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **stack_a, t_data **stack_b, t_lst *data)
{
    ft_swap_a(stack_a, "sa", data);
    ft_swap_b(stack_b, "sb", data);
    ft_ops("ss", data);
}

// int main(int ac, char **av)
// {
//     t_data  *a;
//     t_data  *b;

//     a = convert_av(&a, av);
//     b = convert_av(&b, av);
//     ss_movement(&a, &b);
//     if (ac > 1)
//     {
//         while (a)
//         {
//             printf("%d\n", a->content);
//             a = a->next;
//         }
//         write(1, "\n", 1);
//         while (b)
//         {
//             printf("%d\n", b->content);
//             b = b->next;
//         }
//     }
//     return (0);
// }