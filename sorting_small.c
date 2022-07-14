/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:36:54 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/14 23:30:10 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Recuperer la plus petite valeur.
// Commencer un premier trie de 3 en se basant des index recuperer avec la fonction "ft_position"
// Puis un second de 5
// Verifier d autre posibilite 

// 
int ft_smallest_value(t_data **stack)
{
    t_data  *tmp;

    if (!stack || !(*stack))
        return (0);
    tmp = (*stack);
    while (ft_lstmin(stack) != tmp->content)
        tmp = tmp->next;
    (*stack)->id = tmp->content;
    return ((*stack)->id);
}

void    ft_min_sorting(t_data **stack)
{
    int id;
    t_data *tmp;
    
    ft_position(stack);
    id = ft_smallest_value(stack);
    if (!stack || !(*stack))
        return ;
    tmp = (*stack);
    if (id == 2)
    {
        if (tmp->content > tmp->next->content)
        {
            ft_swap_a(stack);
            ft_rrotate_a(stack);
        }
    }
    else if (id == 0)
    {
        ft_rotate_a(stack);
        ft_swap_a(stack);
    }
    else if (id == 1)
    {
        if (tmp->content > tmp->next->next->content)
                ft_rotate_a(stack);
        else
            ft_swap_a(stack);
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