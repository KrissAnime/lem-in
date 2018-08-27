/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_grow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:29:06 by cbester           #+#    #+#             */
/*   Updated: 2018/08/27 12:26:51 by cbester          ###   ########.fr       */
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
	while (curr[x])
	{
		new[x] = ft_strdup(curr[x]);
		free(curr[x]);
		x++;
	}
	new[x++] = ft_strdup(line);
	new[x] = NULL;
	free(curr);
//	free_array(curr, y - 1);
	return (new);
}
