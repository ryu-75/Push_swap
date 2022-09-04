/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:52 by nlorion           #+#    #+#             */
/*   Updated: 2022/09/02 14:35:54 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// ---------------------------- STRUCTURE -------------------------------- //

typedef struct s_data
{
	int				content;
	int				pos;
	int				idx;
	int				size;
	struct s_data	*next;
}		t_data;

typedef struct s_obj
{
	int	i;
	int	j;
}		t_obj;

// ----------------------------- PARSING --------------------------------- //

t_data	*convert_av(t_data **stack, char **av);
int		ft_error(t_data **stack, int arg);

// ------------------------------ UTILS ---------------------------------- //

long	ft_atols(const char *nptr);
int		have_num(char *nb);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isnumber(int nb);
int		is_num(char *str);

// ----------------------------- LIST UTILS ------------------------------ //

t_data	*add_newlst(t_data *new, int el);
t_data	*ft_lstmin(t_data **stack);
void	ft_lstadd_back_value(t_data **lst, t_data *new);
void	ft_lstdel(t_data *stack, void (*del)(void *));
void	ft_clear_stack(t_data **stack, void (*del)(void *));
int		ft_lst_is_sort(t_data **stack);
int		ft_lsize(t_data *lst);

// ----------------------------- A & B MOVEMENT --------------------------- //

void	ft_swap(t_data **stack, char *s);
void	ft_push_a(t_data **b, t_data **a);
void	ft_push_b(t_data **a, t_data **b);
void	ft_rotate(t_data **stack, char *s);
void	ft_rrotate(t_data **stack, char *s);
void	rrr_movement(t_data **a, t_data **b);
void	rr_movement(t_data **a, t_data **b);

// ------------------------------ ALGO ------------------------------------- //

t_data	*ft_found_target(t_data **a, t_data **b);
t_data	*hash_list(t_data **stack);
void	radix_sort(t_data **stack_a, t_data **stack_b);
void	index_it(t_data **stack);
void	ft_sorting_tab(int **tab, int size);
int		get_index_max(t_data **stack);
void	ft_select_sort(t_data **a, t_data **b);
int		ft_set_pos(t_data **stack);
int		ft_smallest_value(t_data **stack);

#endif