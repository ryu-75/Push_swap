/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:22:42 by nlorion           #+#    #+#             */
/*   Updated: 2022/08/22 23:22:42 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// This function allow to sort three numbers
static void ft_move_3(t_data **a)
{
    int pos;
    
    index_it(a);
    pos = ft_smallest_value(a);
    if (ft_lst_is_sort(a) == 1)
        return (exit(0));
    if (pos == 2)
    {   
        if ((*a)->content > (*a)->next->content)
            ft_swap(a, "sa", (*a));
        ft_rrotate(a, "rra", (*a));
    }
    else if (pos == 0)
    {
        ft_swap(a, "sa", (*a));
        ft_rotate(a, "ra", (*a));
    }
    else
    {
        if ((*a)->content > (*a)->next->next->content)
            ft_rotate(a, "ra", (*a));
        else
            ft_swap(a, "sa", (*a));
    }
}

// Move to the top the most minimal value 
static void ft_small_move(t_data **a, t_data **b)
{
    int small_content;
    int smallest_id;
    int stack_len;
    (void) b;
    stack_len = ft_set_pos(a);
    smallest_id = ft_smallest_value(a);
    small_content = ft_lstmin(a)->content;
    if (smallest_id > stack_len / 2)
    {
        while ((*a)->content != small_content)
            ft_rrotate(a, "rra", (*a));
    }
    else if (smallest_id <= stack_len / 2)
    {
        while ((*a)->content != small_content)
            ft_rotate(a, "ra", (*a));
    }
    ft_push_b(a, b, "pb", (*a));
}

// This function allow to sort four to five numbers
static void ft_move_4_5(t_data **a, t_data **b)
{
    int pos;
    
    pos = ft_set_pos(a);
    if (ft_lst_is_sort(a) == 1)
        return (exit(0));
    if (pos == 4)
    {
        ft_small_move(a, b);
        pos = ft_set_pos(a);
        ft_move_3(a);
        ft_push_a(b, a, "pa", (*a));
    }
    else if (pos == 5)
    {
        ft_small_move(a, b);
        ft_small_move(a, b);
        pos = ft_set_pos(a);
        ft_move_3(a);
        ft_push_a(b, a, "pa", (*a));
        ft_push_a(b, a, "pa", (*a));
    }
}

void    ft_select_sort(t_data **a, t_data **b)
{
    t_data   *tmp;
    int pos;

    pos = ft_set_pos(a);
    tmp = (*a);

    if (pos == 2)
    {
        if (tmp->content > tmp->next->content)
            ft_swap(a, "sa", (*a));
    }
    else if (pos == 3)
        ft_move_3(a);
    else if (pos == 4 || pos == 5)
        ft_move_4_5(a, b);
}

// CORRIGER
/**
 * L'algo de trie des 3 a 5 valeur
 */

// FAIRE
/**
 *  Set les id en les indexantx par leurs tailles 
 * 
 *  Bien recuperer la median par la division de la taille de la stack par 3
 * 
 *  Recuperer la low median et la high median puis renvoyer les valeurs correspondantes 
 *  dans la stack B. Finir par les valeurs en dessous des deux medianes
 * 
 *  Le pre tri est fait apres ca
 * 
 *  Faire les fonctions qui vont permettre de recuperer le nombre de coup pour push les valeurs de B dans A
 *  (Check ca avant le pre tri avec 10 ou 20 valeurs)
 * 
 *  Une fois le calcule de coup fonctionnel faire en sorte de push_a en se basant sur le nombre de coup pour
 *  finir le tri
 * 
 */