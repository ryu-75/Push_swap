#include "push_swap.h"

// Check if av have a num or if av have double
// Return an error if one condition is true

int check_arg(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        if (have_num(av[i]) == 0)
        {
            return (write(1, "Error\n", 6), exit(1), 0);
        }
        i++;
    }
    i = 0;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (strcmp(av[i], av[j]) == 0)
            {
                return (write(1, "Error\n", 6), exit(1), 0);
            }
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

    i = 1;
    value = malloc(sizeof(int) * ft_nblen(nb) + 1);
    if (!value)
        return (0);
    while (av[i])
    {
        if (!check_arg(av))
            return (0);
        nb = ft_atoi(av[i]);
        value[i++] = nb;
    }
    return (*value);
}

t_data *add_to_stack(int ac, char **av)
{
    int i;
    int *value;
    t_data  *stack_a;

    stack_a = NULL;
    i = 0;
    if (!stack_a)
        stack_a = malloc(sizeof(t_data));
    while (i < ac)
    {
        value[i++] = convert_av(ac, av);
        ft_lstadd_back_value(&stack_a, add_newlst(stack_a, *value));
        *stack_a = *stack_a->next;
    }
    return (stack_a);
}

int main(int ac, char **av)
{
    int i;
    t_data  *test;

    test = add_to_stack(ac, av);
    i = 1;
    // if (ac >= 1)
    // {
    //     while (test)
    //     {        
    //         printf("%d\n", test->content);
    //         test = test->next;
    //     }
    // }
    if (ac > 1)
    {
        while (i < ac)
        {        
            printf("%d\n", convert_av(ac, &av[i++]));
        }
    }
    return (0);
}