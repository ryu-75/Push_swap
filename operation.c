/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:42:30 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/15 12:42:30 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void    ft_ops(char *str, t_lst *op)
{
    t_op  *tmp;
    t_op  *new;

    new = malloc(sizeof(t_lst));
    if (!new)
        return ;
    new->operation = str;
    new->next = NULL;
    if (!op->oplst)
    {
        op->oplst = new;
        return ;
    }
    tmp = op->oplst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void    ft_print_op(t_lst **stack)
{
    t_op  *tmp;
    t_obj o = {.i = 1};
    tmp = (*stack)->oplst;
    while (tmp && tmp->next)
    {
        if (ft_strncmp(tmp->operation, "rra", 3) == 0
            && ft_strncmp(tmp->operation, "rrb", 3) == 0)
                tmp = (printf("rrr\n"), tmp->next->next);
        else if (ft_strncmp(tmp->operation, "rrb", 3) == 0
            && ft_strncmp(tmp->operation, "rra", 3) == 0)
                tmp = (printf("rrr\n"), tmp->next->next);
        else if (ft_strncmp(tmp->operation, "sa", 2) == 0
            && ft_strncmp(tmp->operation, "sb", 2) == 0)
                tmp = (printf("ss\n"), tmp->next->next);
        else if (ft_strncmp(tmp->operation, "sb", 2) == 0
            && ft_strncmp(tmp->operation, "sa", 2) == 0)
                tmp = (printf("ss\n"), tmp->next->next);
        else
            printf("%s\n", tmp->operation);
        o.i++;
        tmp = tmp->next;
    }
    if (tmp)
        printf("%s\n", tmp->operation);
    printf("Nb mouvement : %d\n", o.i);
}