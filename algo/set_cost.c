#include "../include/push_swap.h"

void    ft_set_cost(t_data **stack)
{
    t_data  *head;
    int size;

    head = *stack;
    size = ft_lsize(*stack);
    while (head)
    {
        if (head->pos >= size / 2)
            head->cost = head->pos - size;
        else
            head->cost = head->pos;
        head = head->next;
    }
}

t_data  *ft_found_target(t_data **a, t_data **b)
{
    if ((*a)->idx < (*b)->idx && ft_lst_last(b)->idx > (*a)->idx)
        return (*a);
    else if ((*b)->idx < ft_lstmin(a)->content)
        return (ft_lstmin(a));
    else if ((*b)->idx > ft_lstmax(a)->content)
    {
        if (ft_lstmax(a)->next)
            return (*a);
    }
    return (NULL);
}