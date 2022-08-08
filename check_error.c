/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:06:04 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/09 00:06:38 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int    ft_error(t_data **stack, int arg)
{
    arg = EXIT_FAILURE;

    ft_clear_stack(stack, NULL);
    if (arg)
        write(1, "Error\n", 6);
    return (exit(1), EXIT_FAILURE);
}