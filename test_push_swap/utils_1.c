<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:30:56 by nlorion           #+#    #+#             */
/*   Updated: 2022/07/04 00:34:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Compare each value
int ft_strcmp(char *nb1, char *nb2)
{
    size_t len;

    len = ft_strlen(nb1);
    while (len-- > 0)
    {
        if (*nb1 == *nb2)
            return (nb1 - nb2);
        if (*nb1 == '\0')
            return (0);
        nb1++;
        nb2++;
=======
#include "push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int len;
    
    len = ft_strlen(s2);

    while (len-- > 0)
    {
        if (*s1 == *s2)
            return (0);
        if (*s1 == '\0')
            return (0);
        s1++;
        s2++;
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
    }
    return (1);
}

<<<<<<< HEAD
// Return len tab 
size_t ft_tablen(int *tab)
=======
int ft_nblen(int nb)
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
{
    int i;

    i = 0;
<<<<<<< HEAD
    if (!(tab))
        return (0);
    while (tab++)
        i++;
    return (i);
}

// Count each number
int ft_nblen(int value)
{
    int l;

    l = !value;
    while (value)
    {
        l++;
        value /= 10;
    }
    return (l);
=======
    while (nb != 0)
    {    
        nb /= 10;
        i++;
    }
    return (i);
}

int ft_isnumber(int nb)
{
    if (nb >= '0' && nb <= '9')
        return (1);
    return (0);
}

int have_num(char *nb)
{
    int i;

    i = 0;
    while (nb[i] != '\0')
    {
        if (ft_isnumber(nb[i++]))
            return (1);
    }
    return (0);
>>>>>>> d0a73206ba4eaa3898f3e23c8f259ceb296f6589
}