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


int ft_strcmp(const char *s1, const char *s2);
char    exit_fail();
int get_my_nb(char *str);
char	*ft_sjoin(char const *s1, char const *s2);
#endif