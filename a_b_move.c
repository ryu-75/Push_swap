/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/23 16:18:10 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **a, t_data **b, t_data *data)
{
    ft_rrotate(a, "rra", data);
    ft_rrotate(b, "rrb", data);
    ft_ops("rrr", data);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **a, t_data **b, t_data *data)
{
    ft_swap(a, "sa", data);
    ft_swap(b, "sb", data);
    ft_ops("ss", data);
}