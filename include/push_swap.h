/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:52 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/09 17:53:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../Libft/libft.h"

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
t_data  *convert_av(t_data **stack, char **av);

// ------------------------------ UTILS ------------------------------------ //

int ft_nblen(int nb);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);
void    ft_error();
long long	ft_convert_value(const char *nptr);

// ----------------------------- LIST UTILS -------------------------------- //

t_data  *add_newlst(t_data *new, int el);
void    ft_lstadd_back_value(t_data **lst, t_data *new);
void	ft_lstdel(t_data *stack, void (*del)(int));
void	ft_clear_stack(t_data **stack, void (*del)(int));
void	ft_del_firstel(t_data **stack);
void	ft_addfront(t_data **stack, t_data *new);
void	ft_del_lastel(t_data **stack);

// ----------------------------- A MOVEMENT -------------------------------- //

void    ft_swap_a(t_data **stack_a);
void    ft_push_a(t_data **stack_b, t_data **stack_a);
void    ft_rotate_a(t_data **stack_a);
void    ft_rrotate_a(t_data **stack_a);

// ----------------------------- B MOVEMENT -------------------------------- //

void    ft_push_b(t_data **stack_a, t_data **stack_b);
void    ft_swap_b(t_data **stack_b);
void    ft_rotate_b(t_data **stack_b);
void    ft_rrotate_b(t_data **stack_b);
#endif