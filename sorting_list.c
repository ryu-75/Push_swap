#include "include/push_swap.h"

// Faire en sorte de trier une liste a 3 nombre

void    ft_sorted_three(t_data **stack)
{
    t_data  *tmp;
    // t_obj o = {0};
    int swapped;

    if (!stack || !(*stack))
        return ;
    while (swapped)
    {   
        swapped = 0;
        tmp = (*stack);
        while (tmp->next)
        {
            if (tmp->content > tmp->next->content)
            {
                ft_swap_a(&tmp);
                swapped = 1;
            }
            tmp = tmp->next;
        }
    }
}

