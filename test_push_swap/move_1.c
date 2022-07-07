/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:23:36 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/06 20:02:04 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data  *ft_rotate_a(t_data *stack)
{
    t_data  *tmp;

    tmp = NULL;
    if (!stack)
        return (stack);
    tmp->content = stack->next->content;
    stack->next->content = stack->content;
    stack->content = tmp->content;
    return (stack);
}

void    ft_printlst(t_data *stack_a)
{
    int i;

    i = 0;
    printf("%d\n", stack_a->content);
}

int main(int ac, char **av)
{
    t_data *lst;
    t_obj o = {1};
    
    if (ac > 1)
    {
        lst = convert_av(ac, &av[o.i++]);
        ft_rotate_a(lst);
    }
    return (0);
}