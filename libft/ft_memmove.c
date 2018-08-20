/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 06:53:40 by cbester           #+#    #+#             */
/*   Updated: 2018/05/25 11:30:53 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;
	t_byte	*tmpsrc;
	t_byte	*tmpdst;

	index = 0;
	tmpdst = (t_byte*)dst;
	tmpsrc = (t_byte*)src;
	if (src < dst)
	{
		while (len--)
			tmpdst[len] = tmpsrc[len];
	}
	else
	{
		while (index < len)
		{
			tmpdst[index] = tmpsrc[index];
			index++;
		}
	}
	return (dst);
}
