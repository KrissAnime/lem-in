/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 07:54:35 by cbester           #+#    #+#             */
/*   Updated: 2018/06/01 11:16:15 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && len >= j)
	{
		if (haystack[i] == needle[0]
				&& (ft_memcmp(&haystack[i], needle, j) == 0))
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
