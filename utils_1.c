#include "push_swap.h"

char    exit_fail()
{
    ft_putstr_fd("Error\n", 1);
    return (1);
}

int ft_check_db(int *data, int index, long int num)
{
    int i;

    i = 0;
    while (i < index)
    {
        if (data[i] == num)
            return (1);
        i++;
    }
    return (0);
}

int ft_have_num(char *str)
{
    while (*str)
    {
        if (ft_isdigit(*str++))
            return (1);
    }
    return (0);
}

int ft_isnum(char *str)
{
    if ((*str == '+' || *str == '-') && ft_strlen(str) > 1)
        str++;
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int get_my_nb(char *str)
{
    int i;
    int neg;
    int value;

    value = 0;
    i = 0;
    neg = 1;
    while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t' || str[i] == 32)
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    return (value * neg);
}
