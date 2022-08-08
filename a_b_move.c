/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/08 12:25:36 by nlorion          ###   ########.fr       */
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