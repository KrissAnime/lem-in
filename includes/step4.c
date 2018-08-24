/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/24 08:14:25 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
**	Creates links between rooms and plots them in 2-D array
*/

/*void	route(t_ant **ant)
{}*/

static size_t	location(t_ant **ant)
{
	size_t	loc;
	size_t	end;

	loc = 0;
	end = ft_array_size((*ant)->path) - 1;
	while ((*ant)->pos[loc][0])
	{
		if (ft_strequ((*ant)->path[end], (*ant)->pos[loc][0]))
			return (loc);
		loc++;
	}
	return (0);
}

static size_t	map(t_ant **ant, int x, int loc, size_t l)
{
	size_t	y;
	size_t	i;
	size_t	e;

	i = -1;
	while ((*ant)->pos[loc][x])
	{
		y = next_room(ant, loc);
		if (y != 0)
		{
	//		(*ant)->path[i - 1] = pass((*ant)->path[i - 1]);
			while (++i < (*ant)->msize - 1)
			{
				e = -1;
				while ((*ant)->pos[i][++e])
				{
					if (ft_strcmp((*ant)->path[l], (*ant)->pos[i][e]) == 0)
						(*ant)->pos[i][e] = pass((*ant)->pos[i][e]);
				}
			}
			(*ant)->pos[loc][x] = pass((*ant)->pos[loc][x]);
			(*ant)->path = ft_array_grow((*ant)->path, (*ant)->pos[loc][y]);
			return (1);
		}
		else
			break ;
		x++;
	}
//	(*ant)->pos[loc][x] = pass((*ant)->pos[loc][x]);
//	(*ant)->path[i] = pass((*ant)->path[i]);
//	printf("shrinking?\n");
//	print_array((*ant)->path, '\n', 1);
	(*ant)->path = ft_array_shrink((*ant)->path);
//	print_array((*ant)->path, '\n', 1);
//	ft_putchar('\n');
	return (0);
}

size_t	next_room(t_ant **ant, size_t loc)
{
	size_t	x;
	size_t	e;
	size_t	len;

	x = 1;
	e = ft_array_size((*ant)->path);
	while ((*ant)->pos[loc][x])
	{
		len = ft_strlen((*ant)->pos[loc][x]);
//		if (ft_strcmp((*ant)->path[e - 1], (*ant)->pos[loc][x]) == 0)
	//		x++;
		if ((*ant)->pos[loc][x][len - 1] != '-')
			return (x);
		else
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
	size_t	k;

	create_possibilities(ant, 0, 0);
	while (isitover(ant))
	{
		x = 0;
		k = ft_array_size((*ant)->path) - 1;
		if (ft_strcmp((*ant)->pos[loc][x], (*ant)->pos[e][0]) == 0)
		{
		//	(*ant)->path = ft_array_grow((*ant)->path, (*ant)->pos[e][0]);
			return ;
		}
		if (newend(ant, loc, 1, 1) == 1)
			return ;
		map(ant, 0, loc, ft_array_size((*ant)->path) - 1);
		if (ft_strcmp((*ant)->path[k], (*ant)->pos[e][0]) == 0)
			return ;
//		ft_putchar('\n');
//		print_array((*ant)->path, '\n', 1);
//		sleep(3);
		loc = location(ant);
//		sleep(2);
	//	printf("We are in: %s\t Looking at:\t",
//				(*ant)->path[ft_array_size((*ant)->path) - 1]);
//		print_array((*ant)->pos[loc], '\n', 1);
//		ft_putchar('\n');
	//		((*ant)->path[ft_array_size((*ant)->path)])
	}
	print_array((*ant)->path, '\n', 1);
	free_big_array((*ant)->pos);
//	sleep(10);
//	print_array((*ant)->path, '\n', 1);
//	sleep(10);
//	printf("testing function pass: %s\n", pass((*ant)->path[0]));
/*	if (map(ant, -1, -1))
		route(ant);
	else
		ft_putstr("No Valid Route Found");*/
}
