/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 07:20:10 by cbester           #+#    #+#             */
/*   Updated: 2018/05/31 09:00:29 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	index2;

	index = ft_strlen(dst);
	index2 = 0;
	if ((size_t)ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[index2] != '\0' && index + index2 < dstsize - 1)
	{
		dst[index + index2] = src[index2];
		index2++;
	}
	dst[index + index2] = '\0';
	return (ft_strlen(src) + index);
}
