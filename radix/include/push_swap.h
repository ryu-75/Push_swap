/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:52 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/17 17:34:56 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

// ---------------------------- STRUCTURE ----------------------------------- //

typedef struct s_op
{
    struct s_op     *next;
    char    *operation;
}               t_op;

typedef struct s_data
{
    int             content;
    int             pos;
    int             min;
    int             max;
    struct s_data   *next;
}               t_data;

typedef struct s_lst
{
    int             *stack_tab;
    size_t          size_tab;
    t_data          *a;
    t_data          *b;
    t_op            *oplst;
    int             size_a;
    int             size_b;
}               t_lst;

typedef struct s_obj
{
    int i;
    int j;
}               t_obj;

// ----------------------------- PARSING ------------------------------------ //

t_data  *convert_av(t_data **stack, char **av);

// ------------------------------ UTILS ------------------------------------ //

long long	ft_convert_value(const char *nptr);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);
int ft_error(t_data **stack, int arg);
int is_num(char *str);
int ft_lstlen(t_data **stack);
int ft_tablen(char **av);

// ----------------------------- LIST UTILS -------------------------------- //

t_data  *add_newlst(t_data *new, int el);
t_data  *ft_lstmin(t_data **stack);
t_data  *ft_lstmax(t_data **stack);
void    ft_lstadd_back_value(t_data **lst, t_data *new);
void	ft_lstdel(t_data *stack, void (*del)(int));
void	ft_clear_stack(t_data **stack, void (*del)(int));
void	ft_del_firstel(t_data **stack);
void	ft_addfront(t_data **stack, t_data *new);
void	ft_del_lastel(t_data **stack);
int	ft_lst_is_sort(t_data **stack);
int	ft_lsize(t_data *lst);

// ----------------------------- A MOVEMENT -------------------------------- //

void    ft_swap_a(t_data **stack_a, char *s, t_lst *data);
void    ft_push_a(t_data **stack_b, t_data **stack_a, char *s, t_lst *data);
void    ft_rotate_a(t_data **stack_a, char *s, t_lst *data);
void    ft_rrotate_a(t_data **stack_a, char *s, t_lst *data);

// ----------------------------- B MOVEMENT -------------------------------- //

void    ft_swap_b(t_data **stack_b, char *s, t_lst *data);
void    ft_push_b(t_data **stack_a, t_data **stack_b, char *s, t_lst *data);
void    ft_rotate_b(t_data **stack_b, char *s, t_lst *data);
void    ft_rrotate_b(t_data **stack_b, char *s, t_lst *data);

// ------------------------- A and B MOVEMENT ------------------------------ //

void    rrr_movement(t_data **stack_a, t_data **stack_b, t_lst *data);
void    ss_movement(t_data **stack_a, t_data **stack_b, t_lst *data);

// ----------------------------- SORTING ----------------------------------- //

int ft_set_id(t_data **stack);
int ft_smallest_value(t_data **stack);
void    ft_select_sort(t_lst **stack);

// --------------------------- OPERATION ----------------------------------- //

void    ft_ops(char *str, t_lst *op);
void    ft_print_op(t_lst **stack);

#endif