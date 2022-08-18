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
    t_op            *oplst;
    int             content;
    int             pos;
    int             max;
    int             idx;
    struct s_data   *next;
}               t_data;

typedef struct s_obj
{
    int i;
    int j;
}               t_obj;

// ----------------------------- PARSING ---------------------------------- //

t_data  *convert_av(t_data **stack, char **av);

// ------------------------------ UTILS ----------------------------------- //

long long	ft_convert_value(const char *nptr);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);
int ft_error(t_data **stack, int arg);
int is_num(char *str);
int ft_lstlen(t_data **stack);
int ft_tablen(char **av);

// ----------------------------- LIST UTILS ------------------------------- //

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

// ----------------------------- MOVEMENT ---------------------------------- //

void    ft_swap(t_data **stack, char *s, t_data *data);
void    ft_push_a(t_data **stack_b, t_data **stack_a, char *s, t_data *data);
void    ft_push_b(t_data **stack_a, t_data **stack_b, char *s, t_data *data);
void    ft_rotate(t_data **stack, char *s, t_data *data);
void    ft_rrotate(t_data **stack, char *s, t_data *data);
void    rrr_movement(t_data **stack_a, t_data **stack_b, t_data *data);
void    ss_movement(t_data **stack_a, t_data **stack_b, t_data *data);

// --------------------------- OPERATION ----------------------------------- //

void    ft_ops(char *str, t_data *op);
void    ft_print_op(t_data **stack);

// --------------------------- RADIX FUNCTION ------------------------------ //

int get_index_max(t_data *stack);
t_data  *get_next_min(t_data *stack);
void    radix_sort(t_data **stack_a, t_data **stack_b);
t_data  *hash_list(t_data **stack);
void    index_it(t_data **stack);
int	found_distance(t_data **stack, int index);
int ft_set_pos(t_data **stack);
void    ft_small_sort(t_data **stack_a, t_data **stack_b);

void    ft_move_3(t_data **stack);
void    ft_move_4_5(t_data **stack_a, t_data **stack_b);
#endif