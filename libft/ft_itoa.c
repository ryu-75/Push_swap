/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:22:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/13 15:08:21 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_putnbr(long n, char *s, int *i)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, s, i);
		ft_putnbr(n % 10, s, i);
	}
	else
		s[(*i)++] = n + '0';
}

static size_t	ft_countnum(long long n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		n *= -1;
		res++;
	}
	while (n > 9)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		count;
	int		neg;
	int		i;
	long	nbr;

	i = 0;
	neg = 0;
	nbr = n;
	count = ft_countnum(nbr);
	tab = (char *)malloc(sizeof(char) * count + 1);
	if (!tab)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		nbr *= -1;
	}	
	if (neg == 1)
		tab[i++] = '-';
	ft_putnbr(nbr, tab, &i);
	tab[i] = '\0';
	return (tab);
}
