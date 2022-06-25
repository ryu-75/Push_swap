#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "Libft/libft.h"

typedef struct a_list
{
    int     num;
    struct  a_list  *previous;
    struct  a_list   *next;
    
}           a_list;



char    exit_fail();
char    **convert_av(int ac, char **av);

int get_my_nb(char *str);
int ft_strcmp(const char *s1, const char *s2);
int ft_have_num(char *str);
int ft_isnum(char *str);

void    free_tab(char **str);
void    ft_free(void*str);
#endif