/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/21 10:08:44 by cbester          ###   ########.fr       */
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
	size_t	y;

	while ((*ant)->pos[loc][x])
	{
		y = next_room(ant, loc);
		if (y != 0)
		{
			(*ant)->pos[loc][x] = pass((*ant)->pos[loc][x]);
			(*ant)->path = ft_array_grow((*ant)->path, (*ant)->pos[loc][y]);
			return (1);
		}
		else
			break ;
		x++;
	}
	while (ft_findchar((*ant)->path[ft_array_size((*ant)->path) - 1], '-') == 0)
		(*ant)->path = ft_array_shrink((*ant)->path);
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
	(*ant)->path = new_array((*ant)->pos[(*ant)->stin][0]);
}

void	find_links(t_ant **ant, size_t x, size_t loc, size_t e)
{
	create_possibilities(ant, 0, 0);
	while (isitover(ant))
	{
		x = 0;
		while ((*ant)->pos[loc][++x])
		{
			if (ft_strcmp((*ant)->pos[loc][x], (*ant)->pos[e][0]) == 0)
			{
				(*ant)->path = ft_array_grow((*ant)->path, (*ant)->pos[e][0]);
				break ;
			}
			if (newend(ant, loc, 1, 1) == 1)
				return ;
		//	print_array((*ant)->path, '\n', 1);
			if(map(ant, 1, loc) == 0)
				loc--;
		}
		loc++;
	//	printf("We are in: %s\t Looking at:\t",
//				(*ant)->path[ft_array_size((*ant)->path) - 1]);
	//	print_array((*ant)->pos[loc], '\n', 1);
		//	((*ant)->path[ft_array_size((*ant)->path)])
	}
//	printf("testing function pass: %s\n", pass((*ant)->path[0]));
/*	if (map(ant, -1, -1))
		route(ant);
	else
		ft_putstr("No Valid Route Found");*/
}
