#include "include/push_swap.h"

// Recuperer la plus petite valeur.
// Commencer un premier trie de 3 en se basant des index recuperer avec la fonction "ft_position"
// Puis un second de 5
// Verifier d autre posibilite 
int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    if (!stack || !(*stack))
        return (0);
    tmp = (*stack);
    while (tmp)
    {
        if (ft_lstmin(&tmp))
        {
        }
    }
}

// Faire en sorte de trier une liste a 3 nombre
// t_data  *ft_sorted_three(t_data **stack, int count)
// {
//     t_data  *tmp1;
//     t_data  *tmp2;
//     t_obj o = {0};
//     int swap;
// 
//     if (!stack || !(*stack))
//         return (NULL);
//     while (o.i++ <= count)
//     {
//         swap = 0;
//         tmp1 = (*stack);
//         tmp2 = tmp1;
//         while (o.j++ < count - o.i - 1)
//         {
//             if (tmp2->content > tmp1->next->content)
//             {
//                 ft_swap_a(&tmp1);
//                 swap = 1;
//                 printf("%d\n", tmp1->content);
//             }
//             tmp1 = tmp1->next;
//         }
//     }
//     if (swap == 0)
//         return (NULL);
//     return (*stack);
// }

// t_data  *ft_sorted_three(t_data **stack, int count)
// {
//     t_data  *tmp;
//     t_obj o = {0};
    
//     if (!stack || !(*stack))
//         return (NULL);
//     tmp = (*stack);
//     ft_lstmin(&tmp);
//     ft_lstmax(&tmp);
//     while (o.i++ <= count && tmp->next)
//     {
//         if (tmp->content > tmp->next->content->content)
//         {
//             ft_rrotate_a(&tmp);
//         }
//         tmp = tmp->next;
//     }
//     return (*stack);
// }