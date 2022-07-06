<<<<<<< HEAD
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
=======
#include "push_swap.h"

// Check if av have a num or if av have double
// Return an error if one condition is true

int check_arg(char **av)
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
{
    int i;
    int j;

<<<<<<< HEAD
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

=======
    i = 1;
    while (av[i])
    {
        if (have_num(av[i]) == 0)
            return (write(1, "Error\n", 6), exit(1), 0);
        i++;
    }
    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (strcmp(av[i], av[j]) == 0)
                return (write(1, "Error\n", 6), exit(1), 0);
            j++;
        }
        i++;
    }
    return (1);
}

t_data  *convert_av(int ac, char **av)
{
    int i;
    t_data  **stack_a;

    stack_a = malloc(sizeof(t_data**));
    i = 1;
    while (av[i])
    {
        if (!check_arg(av))
            return (NULL);
        ft_lstadd_back_value(stack_a, add_newlst(*stack_a, ft_atoi(av[i++])));
        printf("%d\n", (*stack_a)->content);
        *stack_a = (*stack_a)->next;
    }
    return (*stack_a);
}

void    ft_printlst(t_data *stack_a)
{
    int i;

    i = 0;
    if (!stack_a)
        stack_a = malloc(sizeof(t_data));
    printf("%d\n", stack_a->content);
}

int main(int ac, char **av)
{
    int i;
    i = 1;
    // if (ac >= 1)
    // {
    //     while (test)
    //     {        
    //         printf("%d\n", test->content);
    //         test = test->next;
    //     }
    // }
    if (ac > 1)
    {
        // while (i++ < ac)
        // {        
            convert_av(ac, av);
        // }
    }
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
    return (0);
}