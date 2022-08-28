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

#include "../Libft/libft.h"

// ---------------------------- STRUCTURE ----------------------------------- //

typedef struct s_data
{
    int             content;
    int             pos;
    int             idx;
    int             id;
    int             cost;
    int             abs;
    int             max;
    int             count;
    int             size;
    struct s_data   *next;
}               t_data;

typedef struct s_obj
{
    int i;
    int j;
    int median;
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
t_data  *ft_lst_last(t_data **stack);

// ----------------------------- A & B MOVEMENT -------------------------------- //

void    ft_swap(t_data **stack, char *s);
void    ft_push_a(t_data **b, t_data **a);
void    ft_push_b(t_data **a, t_data **b);
void    ft_rotate(t_data **stack, char *s);
void    ft_rrotate(t_data **stack, char *s);

// ------------------------- AB MOVEMENT ------------------------------ //

void    rrr_movement(t_data **a, t_data **b);
void    rr_movement(t_data **a, t_data **b);
void    ss_movement(t_data **a, t_data **b);

// ----------------------------- SORTING ----------------------------------- //

int ft_set_pos(t_data **stack);
int ft_smallest_value(t_data **stack);
void    ft_select_sort(t_data **a, t_data **b);
int found_median(t_data **stack_a);
void    ft_pre_sort(t_data **a, t_data **b);
int ft_is_chunck(t_data **stack, int med);

// ------------------------------ COST ------------------------------------- //

void    ft_set_cost(t_data **stack);


void ft_sorting_tab(int **tab, int size);
int small_id_finder(t_data **stack, int low_val);
int get_index_max(t_data **stack);
t_data  *hash_list(t_data **stack);
void    index_it(t_data **stack);
void    ra_or_rra(t_data **stack, int size, int pos);
int ft_largest_value(t_data **stack);
void ft_stack_tab(t_data **stack);
t_data  *ft_found_target(t_data **a, t_data **b);
void    ft_final_move(t_data **stack_a, t_data **stack_b, int cost_a, int cost_b);
t_data  *ft_cheap_cost(t_data **b);
int ft_best_cost(int c_a, int c_b);
void    ft_set_abs(t_data **a, t_data **b);
void    radix_sort(t_data **stack_a, t_data **stack_b);

void    last_sort(t_data **stack_a);
#endif