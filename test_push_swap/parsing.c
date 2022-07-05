#include "push_swap.h"

// Check if av have a num or if av have double
// Return an error if one condition is true

int check_arg(char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        if (have_num(av[i]) == 0)
            return (write(1, "Error\n", 6), exit(1), 0);
        i++;
    }
    i = 1;
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

t_data  *convert_av(int ac, char **av)
{
    int i;
    t_data  **stack_a;

    stack_a = malloc(sizeof(t_data**));
    i = 1;
    while (av[i])
    {
        if (!check_arg(av))
            return (NULL);
        ft_lstadd_back_value(stack_a, add_newlst(*stack_a, ft_atoi(av[i++])));
        printf("%d\n", (*stack_a)->content);
        *stack_a = (*stack_a)->next;
    }
    return (*stack_a);
}

void    ft_printlst(t_data *stack_a)
{
    int i;

    i = 0;
    if (!stack_a)
        stack_a = malloc(sizeof(t_data));
    printf("%d\n", stack_a->content);
}

int main(int ac, char **av)
{
    int i;
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
        // while (i++ < ac)
        // {        
            convert_av(ac, av);
        // }
    }
    return (0);
}