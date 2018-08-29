/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:35:10 by cbester           #+#    #+#             */
/*   Updated: 2018/08/28 12:04:21 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	free_ant(t_ant **ant, size_t level)
{
	size_t	x;

	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	free_array((*ant)->links, ft_array_size((*ant)->links));
	x = 0;
	while ((*ant)->pos[x])
		x++;
	while ((*ant)->pos[x])
	{
		free_array((*ant)->pos[x], ft_array_size((*ant)->pos[x]));
		x--;
	}
	if (level > 2)
		free_array((*ant)->path, ft_array_size((*ant)->path));
}
