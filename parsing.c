#include "push_swap.h"

a_list *add_node_front(a_list *stack_a, char *str)
{
    a_list    *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    stack_a = new;
    if (!new->num)
        return (NULL);
    new->next = NULL;
    return (new);
}

a_list  *add_node_back(a_list *stack_a, char *str)
{
    a_list  *new;

    new = malloc(sizeof(a_list));
    if (!new)
        return (NULL);
    if (!new)
    {
        stack_a = new;
        return (NULL);
    }
    while (new->next)
        new = stack_a->next;
    new->next = NULL;
    return (new);
}

a_list  *print_list(a_list *stack_a, char *str)
{
    
}

int main(void)
{
    a_list  *node;
    char    *s = "3468";
    
    node = NULL;
    
    //print_node(node);
    
    return (0);
}
