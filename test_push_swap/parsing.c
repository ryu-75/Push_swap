/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:59:46 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/04 01:26:07 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if av contain no double and have only digit
int check_arg(int ac, char **av)
{
    int i;
    int j;

        i = 1;
        while (av[i])
        {
            if (ft_isdigit(*av[i]) == 0)
                return (0);
            i++;
        }
        i = 1;
        while (av[i])
        {
            j = i + 1;
            while (av[j])
            {
                if (ft_strcmp(av[i], av[j]) == 1)
                    return (0);
                j++;
            }
            i++;
        }
    return (1);
}

// Convert each av to integer and stack it into an int array
int convert_av(int ac, char **av)
{
    int i;
    long long num;
    int *value;

    i = 0;
    value = malloc(sizeof(int) * ft_nblen(num) + 1);
    if (!value)
        return (0);
    if (*av[i] == '+' || *av[i] == '-' && i > 1)
        return (0);
    while (i < ac && av[i])
    {
        num = ft_atoi(av[i]);
        if (num <= INT_MIN || num >= INT_MAX)
            return (0);
        value[i++] = (int)num;
        i++;
    }
    return (*value);
}

// Dans cette fonction, j'essaye de récupérer chaque valeur pour ensuite les stocker dans
// mon tableau de int contenu dans ma structure.

void    ft_lstarg(t_data *lst, int ac, char **av)
{
    int *value;
    int i;
    
    lst = malloc(sizeof(t_data));
    *value = convert_av(ac, av);
    lst->data_size = ft_nblen(*value);
    lst->data = malloc(sizeof(int) * (size_t)lst->data_size + 1);
    if (!lst->data || !lst)
        return ; 
    i = 1;
    while (i < (int)lst->data_size)
    {
        lst->data[i++] = (int)value;
        value++;
    }
    printf("value = %d\n", *value);
    i = 1;
    int y = 1;
    if (ac > 1)
    {
        while (y < ac)
            printf("return %d = %d\n", i++, lst->data[y++]);
    }
}

int main(int ac, char **av)
{
    t_data *lst;

    lst = NULL;

        ft_lstarg(lst, ac, av);

    return (0);
}