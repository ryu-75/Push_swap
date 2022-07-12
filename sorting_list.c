#include "include/push_swap.h"

// Faire en sorte de trier une liste a 3 nombre
t_data  *ft_sorted_three(t_data **stack, int count)
{
    t_data  *tmp;
    t_obj o = {0};
    int swap;

    if (!stack || !(*stack))
        return (NULL);
    while (o.i++ <= count)
    {
        swap = 0;
        tmp = (*stack);
        while (o.j++ < count - o.i - 1)
        {
            if (tmp->content > tmp->next->content)
            {
                ft_swap_a(&tmp);
                swap = 1;
            }
            tmp = tmp->next;
        }
    }
    if (swap == 0)
        return (NULL);
    return (*stack);
}