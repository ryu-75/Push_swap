/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/17 16:01:16 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **stack_a, t_data **stack_b, t_data *data)
{
    ft_rrotate(stack_a, "rra", data);
    ft_rrotate(stack_b, "rrb", data);
    ft_ops("rrr", data);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **stack_a, t_data **stack_b, t_data *data)
{
    ft_swap(stack_a, "sa", data);
    ft_swap(stack_b, "sb", data);
    ft_ops("ss", data);
}