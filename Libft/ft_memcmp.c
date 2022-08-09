/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:26:08 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/07 20:53:00 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	if (n != 0)
	{
		while (n-- > 0)
		{
			if (*p1++ != *p2++)
			{
				if (p1[-1] < p2[-1])
					return (-1);
				else
					return (1);
			}
		}
	}
	return (0);
}
