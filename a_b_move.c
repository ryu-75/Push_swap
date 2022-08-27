/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:37:09 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/27 14:18:19 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Stack a and stack b reverse rotate at the same time
void    rrr_movement(t_data **a, t_data **b)
{
    ft_rrotate(a, "rra");
    ft_rrotate(b, "rrb");
    write(1, "rrr", 3);
    ft_putstr_fd("rrr\n", 0);
}

// Stack a and stack b swap at the same time
void    ss_movement(t_data **a, t_data **b)
{
    ft_swap(a, "sa");
    ft_swap(b, "sb");
    write (1, "ss", 2);
    ft_putstr_fd("ss\n", 0);
}