/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:08:07 by cbester           #+#    #+#             */
/*   Updated: 2018/05/22 07:21:13 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte	*tempdst;
	t_byte	*tempsrc;
	size_t	index;

	index = 0;
	tempdst = (t_byte*)dst;
	tempsrc = (t_byte*)src;
	while (index < n)
	{
		tempdst[index] = tempsrc[index];
		index++;
	}
	return (dst);
}
