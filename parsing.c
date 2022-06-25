#include "push_swap.h"

a_list *add_node_front(a_list *stack_a, int *num)
{
    a_list    *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->num = *num;
    new->next = stack_a;
    if (!new->num)
        return (NULL);
    stack_a = new;
    printf("%d\n", stack_a->num);
    return (stack_a);
}

a_list  *add_node_back(a_list *stack_a, int *num)
{
    a_list  *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->next = NULL;
    while (new->next != NULL)
        new = new->next;
    new->num = *num;
    new->next = new;
    stack_a = new;
    printf("%d\n", stack_a->num);
    return (stack_a);
}

a_list  *add_new_node(a_list *new)
{
    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->next = NULL;
    return (new);
}

char    **get_parameters(int ac, char **av)
{
    int index;
    char  **parameters;

    index = 1;
    if (ac > 0)
    {
        parameters = ft_split(av[index], ' ');
        while (parameters[index])
            index++;
    }
    else
    {
        parameters = malloc(ac * sizeof(char));
        if (!parameters)
            return (NULL);
        while (parameters[index + 1])
        {
            parameters[index] = ft_strdup(av[index + 1]);
            index++;
        }
    }
    return (parameters);
}
/*
int main(int argc, char *argv[])
{
    a_list  *tst;
    a_list  *ft;

    int nb[] = {3};
    tst = NULL;
    tst = add_node_front(tst, nb);
    
    return (0);
}
*/