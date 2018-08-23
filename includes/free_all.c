/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:35:10 by cbester           #+#    #+#             */
/*   Updated: 2018/08/23 13:42:57 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static void	extreme_clean(t_ant *ant)
{
	size_t	x;

	x = 0;
	free_array(ant->path, ft_array_size(ant->path));
	while (ant->pos[x])
		x++;
	x--;
//	while (ant->pos[x])
//	{
//		free_array(ant->pos[x], ft_array_size(ant->pos[x]));
//		x--;
//	}
}

void		free_ant(t_ant *ant, size_t level)
{
	size_t	x;

	free_array(ant->rooms, ft_array_size(ant->rooms));
	free_array(ant->links, ft_array_size(ant->links));
//	if (level > 1)
//		free_array(ant->routes, ft_array_size(ant->routes));
	x = 0;
	while (ant->test[x])
		x++;
	x--;
	while (ant->test[x])
	{
		free_array(ant->test[x], ft_array_size(ant->test[x]));
		x--;
	}
	if (level > 2)
		extreme_clean(ant);
	free(ant);
}
