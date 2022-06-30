#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "Libft/libft.h"

typedef struct s_mov
{
    struct s_mov    *next;
    char            *value;
}           t_mov;

typedef struct s_data
{
    int                 *num;
    size_t              data_size;
}           t_data;

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