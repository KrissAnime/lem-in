/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:25:03 by cbester           #+#    #+#             */
/*   Updated: 2018/05/24 06:50:25 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_byte	rep;
	t_byte	*tempdst;
	t_byte	*tempsrc;
	size_t	index;

	index = 0;
	rep = (t_byte)c;
	tempdst = (t_byte*)dst;
	tempsrc = (t_byte*)src;
	while (index < n)
	{
		tempdst[index] = tempsrc[index];
		if (tempsrc[index] == rep)
			return (&dst[index + 1]);
		index++;
	}
	return (NULL);
}
