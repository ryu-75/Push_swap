#include "../include/push_swap.h"

void    ft_cost_a(t_lst *s_a, int pos)
{
    t_data  *t_a;
    int size = ft_lsize(s_a->a);
    t_obj o = {.i = 0};
    
    pos = small_id_finder(s_a->a, ft_lstmin(&s_a->a)->content);
    t_a = s_a->a;
    if (pos <= size / 2)
    {        
        while (o.i++ < size / 2)
            t_a->cost = (pos - size) + 3;
    }
    else if (pos > size / 2)
    {
        while (o.i++ < size)
            t_a->cost = size - (pos + 1);   
    }
}

void    set_cost(t_lst *stack)
{
    t_data  *tmp;
    int pos;

    pos = small_id_finder(stack->a, ft_lstmin(&stack->a)->content);
    tmp = stack->a;
    while (tmp)
    {
        if (pos)
            ft_cost_a(stack, pos);
        tmp = tmp->next;
    }
}