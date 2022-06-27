#include "push_swap.h"

void    ft_free(void *str)
{
    if (str)
    {
        free(str);
        str = NULL;
    }
}

void free_tab(void **str)
{
    void    **ptr;

    ptr = str;
    while (*str++)
    {
        free(*str);
        *str = NULL;
    }
    free(ptr);
    ptr = NULL;
}