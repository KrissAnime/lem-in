/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:11:59 by cbester           #+#    #+#             */
/*   Updated: 2018/08/17 11:14:03 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	**build_link(t_ant **ant, char **curr, char *line)
{
	char	**new;
	size_t	x;

	(*ant)->lsize++;
	x = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->lsize)))
		return (NULL);
	if ((*ant)->msize > 2)
	{
		while (curr[x])
		{
			new[x] = ft_strdup(curr[x]);
			x++;
		}
		free_array(curr, ft_array_size(curr));
	}
	new[x++] = ft_strdup(line);
	new[x] = NULL;
	return (new);
}
