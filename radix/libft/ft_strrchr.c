/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:21:38 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/09 14:59:22 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*ptr;

	tmp = NULL;
	ptr = strchr(s, c);
	if (c == '\0')
		return (strchr(s, '\0'));
	if (ptr != NULL)
		tmp = ptr;
	while (*s)
	{
		if (*s == c)
			tmp = (char *)s;
		if (*s == '\0')
			return (tmp);
		s++;
	}
	return (tmp);
}
