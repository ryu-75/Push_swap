#include "push_swap.h"

a_list *add_node_front(a_list *stack_a, char *str)
{
    a_list    *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->num = get_my_nb(str);
    if (!new->num)
        return (NULL);
    new->next = stack_a;
    stack_a = new;
    return (stack_a);
}

a_list  *add_node_back(a_list *stack_a, char *str)
{
    a_list  *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->num = get_my_nb(str);
    new->next = NULL;
    while (new->next != NULL)
        new = new->next;
    new->next = new;
    stack_a = new;
    return (stack_a);
}

a_list  *add_new_node(char *str)
{
    a_list  *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    new->num = get_my_nb(str);
    new->next = NULL;
    return (new);
}
/*
int count_parameter(int ac, char **av)
{

}
*/
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

int main(int argc, char *argv[])
{
    int i;
    char    **s = get_parameters(argc, argv);
    i = 0;

    if (argc > 1)
    {
        while (argv[i] != 0)
        {
            printf("%s\n", s[i]);
            i++;
        }
    }    
    return (0);
}
