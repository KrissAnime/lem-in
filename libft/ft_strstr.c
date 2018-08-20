/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:26:27 by cbester           #+#    #+#             */
/*   Updated: 2018/05/31 14:23:30 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0]
				&& (ft_memcmp(&haystack[i], needle, j) == 0))
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
