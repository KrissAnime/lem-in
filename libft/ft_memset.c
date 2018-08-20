/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:49:19 by cbester           #+#    #+#             */
/*   Updated: 2018/05/21 12:04:07 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_byte rep;
	t_byte *dest;
	size_t index;

	index = 0;
	rep = (t_byte)c;
	dest = (t_byte*)b;
	while (index < len)
	{
		dest[index] = rep;
		index++;
	}
	return (b);
}
