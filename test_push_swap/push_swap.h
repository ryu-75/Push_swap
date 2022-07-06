<<<<<<< HEAD
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

=======
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

<<<<<<< HEAD
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
=======
// ---------------------------- STRUCTURE ----------------------------------- //

typedef struct s_data
{
    int             content;
    struct s_data   *next;
    // struct s_data   *stack_b;
    //int             size_a;
    //int             size_b;
}               t_data;

// ----------------------------- PARSING ------------------------------------ //

int check_arg(char **av);
t_data    *convert_av(int ac, char **av);

// ------------------------------ UTILS ------------------------------------ //

int ft_nblen(int nb);
int ft_strcmp(const char *s1, const char *s2);
int ft_isnumber(int nb);
int have_num(char *nb);


// ----------------------------- LIST UTILS -------------------------------- //

t_data  *add_newlst(t_data *new, int el);
void	ft_lstadd_back_value(t_data **lst, t_data *new);

void	ft_lstadd_back_test(t_data **lst, int el);
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589

#endif