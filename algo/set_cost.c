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
            return (ft_lstmax(a)->next);
        return (*a);
    }
    while (a)
    {
        if ((a && (*a)->next) && (*a)->idx < (*b)->idx && (*a)->idx > (*b)->idx)
            return ((*a)->next);
    }
    return (NULL);
}

int ft_best_cost(t_data **a, t_data **b)
{
    if ((*a)->cost >= 0 && (*b)->cost >= 0)
    {
        if ((*a)->cost >= 0)
            return ((*a)->cost);
        else
            return ((*b)->cost);
    }
    else if ((*a)->cost < 0 && (*b)->cost < 0)
    {
        if ((*a)->cost < 0)
            return ((*a)->cost * -1);
        else
            return ((*b)->cost * -1);
    }
    else if (((*a)->cost < 0  && (*b)->cost >= 0) ||
        ((*a)->cost >= 0 && (*b)->cost < 0))
    {
        if ((*a)->cost < 0)
            return ((*a)->cost);
        else if ((*a)->cost >= 0)
            return ((*a)->next->cost);
    }
    return (0);
}

// t_data  *ft_set_abs(t_data **a, t_data **b)
// {
//     t_data  *target;

//     ft_set_cost(b);
//     while (*a)
//     {
//         target = ft_found_target(a, b);

//     }
// }

t_data  *ft_cheap_cost(t_data **b)
{
    t_data  *head;
    t_data  *cost;

    head = *b;
    while (head)
    {
        cost = head;
        if (head->abs < cost->abs)
            cost = head;
        head = head->next;
    }
    return (cost);
}