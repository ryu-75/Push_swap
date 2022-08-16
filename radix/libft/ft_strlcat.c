/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:07:26 by nlorion           #+#    #+#             */
/*   Updated: 2022/05/09 18:18:28 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strnlen(dst, size);
	src_len = ft_strlen(src);
	if (dest_len == size)
		return (src_len + size);
	if (src_len < size - dest_len)
		memcpy(dst + dest_len, src, src_len + 1);
	else
	{
		memcpy(dst + dest_len, src, size - dest_len - 1);
		dst[size - 1] = '\0';
	}
	return (dest_len + src_len);
}
