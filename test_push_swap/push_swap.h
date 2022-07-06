/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:52 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/06 19:22:05 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

// ---------------------------- STRUCTURE ----------------------------------- //

typedef struct s_data
{
    int             content;
    struct s_data   *prev;
    struct s_data   *next;
}               t_data;

typedef struct s_stack
{
    struct s_stack  *head;
    struct s_stack  *tail;
}               t_stack;

typedef struct s_obj
{
    int i;
    int j;
    int num;
    int len;
}               t_obj;

// ----------------------------- PARSING ------------------------------------ //

int check_arg(char **av);
t_data    *convert_av(int ac, char **av);

// ------------------------------ UTILS ------------------------------------ //

int ft_nblen(int nb);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);
void    ft_error();

// ----------------------------- LIST UTILS -------------------------------- //

t_data  *add_newlst(t_data *new, int el);
void	ft_lstadd_back_value(t_data **lst, t_data *new);
void	ft_lstadd_back_test(t_data **lst, int el);

#endif