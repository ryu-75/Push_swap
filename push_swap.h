#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "Libft/libft.h"

typedef struct s_stack
{
    int             num;
    struct s_stack  *previous;  // stack_a
    struct s_stack  *next;      // stack_b
}           t_stack;

typedef struct s_data
{
    int                 *num;
    size_t              data_size;
    // struct s_data   *stack_a;
    // struct s_data   *stack_b;  
    // struct  s_data  *next;
}           t_data;

t_stack  *add_new_node(t_stack *new);

char    exit_fail();
char    **split_av(int ac, char **av);
int get_my_nb(char *str);
int ft_strcmp(const char *s1, const char *s2);
int ft_have_num(char *str);
int ft_isnum(char *str);
int ft_check_db(int *data, int index, long int num);

void    add_list(t_data *data, int ac, char **av);
void    free_tab(void **str);
void    ft_free(void *str);
#endif