/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_grow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:29:06 by cbester           #+#    #+#             */
/*   Updated: 2018/08/20 10:53:47 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_grow(char **curr, char *line)
{
	char	**new;
	size_t	x;
	size_t	y;

	x = 0;
	y = ft_array_size(curr) + 1;
	if (!(new = (char**)malloc(sizeof(char*) * y + 1)))
		return (NULL);
	if (y > 1)
	{
		while (curr[x])
		{
			new[x] = ft_strdup(curr[x]);
			x++;
		}
		free_array(curr, y - 1);
	}
	new[x++] = ft_strdup(line);
	new[x] = NULL;
	return (new);
}
