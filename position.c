#include "include/push_swap.h"

t_data  *ft_pos(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = malloc(sizeof(t_data));
    if (!stack || !(*stack) || !pos)
        return (NULL);
    while (o.i++ <= (*stack)->size)
    {
        while (o.j++ <= (*stack)->size && pos->next)
        {
            pos->pos = o.i;
            pos = pos->next;
        }
    }
    return (pos);
}