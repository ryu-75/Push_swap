#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int len;
    
    len = ft_strlen(s2);

    while (len-- > 0)
    {
        if (*s1 == *s2)
            return (0);
        if (*s1 == '\0')
            return (0);
        s1++;
        s2++;
    }
    return (1);
}

int ft_nblen(int nb)
{
    int i;

    i = 0;
    while (nb != 0)
    {    
        nb /= 10;
        i++;
    }
    return (i);
}

int ft_isnumber(int nb)
{
    if (nb >= '0' && nb <= '9')
        return (1);
    return (0);
}

int have_num(char *nb)
{
    int i;

    i = 0;
    while (nb[i] != '\0')
    {
        if (ft_isnumber(nb[i++]))
            return (1);
    }
    return (0);
}