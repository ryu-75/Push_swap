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
    if ((*a)->idx > (*b)->idx && ft_lst_last(a)->idx < (*b)->idx)
        return (*a);
    else if ((*b)->idx < ft_lstmin(a)->idx)
        return (ft_lstmin(a));
    else if (   (*b)->idx > ft_lstmax(a)->idx)
    {
        if (ft_lstmax(a)->next)
            return (ft_lstmax(a)->next);
        return (*a);
    }
    while ((*a))
    {
        if (((*a) && (*a)->next) && ((*a)->idx < (*b)->idx) && ((*a)->next->idx > (*b)->idx))
            return ((*a)->next);
        (*a) = (*a)->next;
    }
    return (NULL);
}

int ft_best_cost(int c_a, int c_b)
{
    if (c_a >= 0 && c_b >= 0)
    {
        if (c_a > c_b)
            return (c_a);
        else
            return (c_b);
    }
    else if (c_a < 0 && c_b < 0)
    {
        if (c_a < c_b)
            return (c_a * -1);
        else
            return (c_b * -1);
    }
    else if ((c_a <= 0 && c_b >= 0) ||
        (c_a >= 0 && c_b <= 0))
    {
        if (c_a < 0)
            c_a *= -1;
        else if (c_b < 0)
            c_b *= -1;
        return (c_a + c_b);
    }
    return (0);
}

void    ft_set_abs(t_data **a, t_data **b)
{
    t_data  *target;
    t_data  *tmp;

    tmp = (*b);
    while (tmp)
    {
        target = ft_found_target(a, b);
        tmp->abs = ft_best_cost(target->cost, tmp->cost);
        tmp = tmp->next;
    }
}

t_data  *ft_cheap_cost(t_data **b)
{
    t_data  *head;
    t_data  *cost;

    head = *b;
    while (head)
    {
        cost = head;
        if (head->abs > cost->abs)
            head = cost;
        head = head->next;
    }
    return (head);
}