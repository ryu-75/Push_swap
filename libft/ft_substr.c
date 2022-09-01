/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:34:28 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/10 14:01:43 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mcheck.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		strlen;
	char		*str;

	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		tab = malloc(sizeof(char));
		*tab = 0;
		return (tab);
	}
	if (strlen < (start + len))
		len = strlen - start;
	tab = (char *)malloc(sizeof(*s) * (len + 1));
	if (!tab)
		return (NULL);
	str = tab;
	while (len--)
	{
		*tab++ = s[start];
		start++;
	}
	*tab = '\0';
	return (str);
}
