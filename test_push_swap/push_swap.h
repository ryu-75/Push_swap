/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:52 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/04 00:54:25 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

typedef struct s_data
{
    int             *data;
    struct s_data       *next;
    struct s_data       *stack_a;
    size_t      data_size;
}           t_data;

// ------------------- Utilities ------------------------ //

int ft_strcmp(char *nb1, char *nb2);
int ft_nblen(int value);
size_t ft_tablen(int *tab);

// -------------------- Checker ------------------------- //

int check_arg(int ac, char **av);
int convert_av(int ac, char **av);

// ------------------List utilities --------------------- //

t_data    *add_lstnew(int value);

#endif