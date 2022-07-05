#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "Libft/libft.h"

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

#endif