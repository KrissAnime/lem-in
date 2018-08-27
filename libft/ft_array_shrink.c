/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_shrink.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:14:27 by cbester           #+#    #+#             */
/*   Updated: 2018/08/27 10:19:15 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_shrink(char **curr)
{
	char	**new;
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_array_size(curr) + 1;
	if (!(new = (char**)malloc(sizeof(char*) * y)))
		return (NULL);
	if (y > 1)
	{
		while (x < y - 1)
		{
			new[x] = ft_strdup(curr[x]);
			x++;
		}
		free_array(curr, y - 1);
	}
	new[x] = NULL;
	return (new);
}
