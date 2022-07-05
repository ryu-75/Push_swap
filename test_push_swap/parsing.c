#include "push_swap.h"

// Check if av have a num or if av have double
// Return an error if one condition is true

int check_arg(int ac, char **av)
{
    int i;
    int j;
    int value;

    i = 0;
    while (av[i])
    {
        if (have_num(av[i]) == 0)
            return (write(1, "Error\n", 6), exit(1), 0);
        i++;
    }
    i = 0;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (strcmp(av[i], av[j]) == 0)
                return (write(1, "Error\n", 6), exit(1), 0);
            j++;
        }
        i++;
    }
    return (1);
}

int convert_av(int ac, char **av)
{
    int i;
    int *value;
    int nb;

    i = 0;
    value = malloc(sizeof(int) * ft_nblen(nb) + 1);
    if (!value)
        return (0);
    while (i <  ac && av[i])
    {
        if (!check_arg(ac, av))
            return (0);
        nb = ft_atoi(av[i]);
        value[i++] = nb;
    }
    return (*value);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac >= 1)
    {
        while (i < ac)
            printf("%d\n", convert_av(ac, &av[i++]));
    }
    return (0);
}