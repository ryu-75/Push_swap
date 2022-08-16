/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:51:53 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/10 17:02:27 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search(const char *str, const char c)
{
	size_t	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*tab;
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_search(set, s1[i]))
		i++;
	if (i == len)
	{
		i = 0;
		len = 0;
	}
	while (s1[i] && ft_search(set, s1[len - 1]))
		len--;
	tab = malloc(sizeof(char) * len -  i + 1);
	if (!tab)
		return (NULL);
	j = 0;
	while (i < len)
		tab[j++] = s1[i++];
	tab[j] = '\0';
	return (str = tab);	
}
