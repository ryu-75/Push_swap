#include "include/push_swap.h"

// Retrieve index of each value in stack 
int ft_set_id(t_data **stack)
{
    t_data  *pos;
    t_obj o = {0};

    pos = (*stack);
	while (pos && pos->next)
    {
        pos->id = o.i++;
        pos = pos->next;
	}
	pos->id = o.i;
    return (o.i + 1);
}