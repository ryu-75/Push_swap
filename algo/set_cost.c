#include "../include/push_swap.h"

t_data  *ft_cheap_cost(t_lst *stack)
{
    t_data  *tmp;
    t_data  *min;
    int size;
    int pos;

    size = ft_lsize(stack->a);
    tmp = stack->a;
    min = tmp;
    pos = small_id_finder(stack->a, ft_lstmin(&stack->a)->content);
    while (tmp)
    {
        if (pos > size / 2)
        {
            if (tmp->content < min->content)
                min = tmp;
        }
        if (pos <= size / 2)
        {
            if (tmp->content < min->content)
                min = tmp;
        }
        tmp = tmp->next;
    }
    return (min);
}

int ft_cost_a(t_lst *s_a, int size)
{
    int cost;
    t_obj o = {.i = 0};
    int pos;

    size = ft_lsize(s_a->a);
    pos = small_id_finder(s_a->a, ft_lstmin(&s_a->a)->content);
    if (pos <= size / 2)
    {        
        while (o.i++ < size / 2)
            cost = pos * -1;
    }
    else if (pos > size / 2)
    {
        while (o.i++ < size)
            cost = size - (pos + 1);   
    }
    printf("%d", cost);
    return (cost);
}

void    set_cost(t_lst *stack)
{
    t_data  *tmp;
    // int pos;
    int size;

    size = ft_lsize(stack->a);
    // pos = small_id_finder(stack->a, ft_lstmin(&stack->a)->content);
    tmp = stack->a->next;
    while (tmp)
    {
        if (ft_lstmin(&stack->a)->content < size / 2)
        {
            if (tmp == ft_lstmin(&stack->a))
                tmp->cost = ft_cost_a(stack, size);
            else
                tmp->cost = 0;
        }
        else if (ft_lstmin(&stack->a)->content > size / 2)
        {
            if (tmp == ft_lstmin(&stack->a))
                tmp->cost = ft_cost_a(stack, size);
            else
                tmp->cost = 0;
        }
        tmp = tmp->next;
    }
}