/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:06 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/04 00:54:21 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data    *add_lstnew(int value)
{
    t_data *tmp;
    
    tmp = malloc(sizeof(t_data));
    if (!value)
        return (NULL);
    tmp->data = &value;
    tmp->next = NULL;
    return (tmp);
}

// int main(void)
// {
//     int new;
//     int add = 45;
//     add_lstnew(add);
    
//     t_data  *lst;
//     lst = malloc(sizeof(t_data));
//     printf("%d\n", lst->data);
//     lst->next = NULL;

//     return (0);
// }