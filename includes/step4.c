/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/20 14:03:38 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
**	Creates links between rooms and plots them in 2-D array
*/

/*void	route(t_ant **ant)
{}*/

size_t	map(t_ant **ant, int x, int loc)
{

	while ((*ant)->pos[loc][x])
	{
		
	}
	return (0);
}

size_t	next_room(t_ant **ant, size_t loc)
{
	size_t	x;

	x = 1;
	while ((*ant)->pos[loc][x])
	{
		if (ft_findchar((*ant)->pos[loc][x], '-') == 0)
			return (x);
		x++;
	}
	return (0);
}



static void	create_possibilities(t_ant **ant, size_t x, size_t y)
{
	char	*temp;

	while (y < (*ant)->msize - 1)
	{
		(*ant)->pos[y] = new_array_free(get_name(ant, y));
		x = 0;
		while ((*ant)->links[x])
		{
			if (has_link((*ant)->links[x], (*ant)->pos[y][0]) == 0)
			{
				temp = get_link((*ant)->links[x], 0, 1);
				(*ant)->pos[y] = ft_array_grow((*ant)->pos[y], temp);
				free(temp);
			}
			else if (has_link2((*ant)->links[x], (*ant)->pos[y][0]) == 0)
			{
				temp = get_link((*ant)->links[x], 0, 0);
				(*ant)->pos[y] = ft_array_grow((*ant)->pos[y], temp);
				free(temp);
			}
			x++;
		}
		y++;
	}
}

void	find_links(t_ant **ant)
{
	size_t	x;

	create_possibilities(ant, 0, 0);
	(*ant)->path = new_array((*ant)->pos[(*ant)->stin][0]);
	while (isitover(ant))
	{
		x = 1;
	//	((*ant)->path[ft_array_size((*ant)->path)])
	}
//	printf("testing function pass: %s\n", pass((*ant)->path[0]));
/*	if (map(ant, -1, -1))
		route(ant);
	else
		ft_putstr("No Valid Route Found");*/
}
