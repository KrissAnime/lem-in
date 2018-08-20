/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:48:05 by cbester           #+#    #+#             */
/*   Updated: 2018/05/24 10:22:49 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	index;

	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		ptr[index] = 0;
		index++;
	}
	return (ptr);
}
