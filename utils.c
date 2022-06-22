#include "push_swap.h"

char    exit_fail()
{
    ft_putstr_fd("Error\n", 1);
    return (1);
}

int ft_isnum(char *str)
{
    if (*str >= 0 && *str <= 9)
        return (1);
    return (0);
}

int ft_strcmp(const char *s1, const char *s2)\
{
    int i;
    int j;

    i = 0;
    while (s1[i] && s1[i] != '\0')
    {
        j = 0;
        while (s2[j] && s2[j] != '\0')
        {
            if (s1[i] == s2[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_strlen(char *nb)
{
    int i;

    i = 0;
    while (nb[i] != '\0' && nb)
        i++;
    return (i);
}
