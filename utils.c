#include "push_swap.h"

char    exit_fail()
{
    ft_putstr_fd("Error\n", 1);
    return (1);
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

int ft_strcmp(const char *s1, const char *s2)
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

/*
int main()
{
    char    *str = "4 5 5 ";

    printf("%d\n", ft_have_num(str));
    return (0);
}
*/