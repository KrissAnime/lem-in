/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:27:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 13:43:14 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
**	Creates links between rooms and plots them in 2-D array
*/

static size_t	location(t_ant **ant)
{
	size_t	loc;
	size_t	end;

	loc = 0;
	end = ft_array_size((*ant)->path) - 1;
	while (*(*ant)->pos[loc])
	{
		if (ft_strequ((*ant)->path[end], *(*ant)->pos[loc]))
			break ;
		loc++;
	}
	return (loc);
}

static size_t	map(t_ant **ant, int x, int loc, size_t l)
{
	size_t	y;
	size_t	i;
	size_t	e;

	i = -1;
	while (x < (int)ft_array_size((*ant)->pos[loc]))
	{
		y = next_room(ant, loc);
		if (y != 0)
		{
			while (++i < (*ant)->msize - 1)
			{
				e = -1;
				while ((*ant)->pos[i][++e])
					if (ft_strequ((*ant)->path[l], (*ant)->pos[i][e]))
						(*ant)->pos[i][e] = pass((*ant)->pos[i][e]);
			}
			(*ant)->pos[loc][x] = pass((*ant)->pos[loc][x]);
			(*ant)->path = build_path(ant, (*ant)->path, (*ant)->pos[loc][y]);
			return (1);
		}
		x++;
	}
	(*ant)->path = break_path(ant, (*ant)->path);
	return (0);
}

size_t			next_room(t_ant **ant, size_t loc)
{
	size_t	x;
	size_t	e;
	size_t	len;

	x = 1;
	e = ft_array_size((*ant)->path);
	while ((*ant)->pos[loc][x])
	{
		len = ft_strlen((*ant)->pos[loc][x]);
		if ((*ant)->pos[loc][x][len - 1] != '-')
			return (x);
		else
			x++;
	}
	return (0);
}

static void		create_possibilities(t_ant **ant, size_t x, size_t y, char **t2)
{
	char	*temp;
	
	while ((*ant)->rooms[y] && y < (*ant)->msize - 1)
	{
		(*ant)->pos[y] = new_array_free(get_name(ant, y));
		x = -1;
		(*ant)->csize = 2;
//		print_array((*ant)->links, '\t', 1);
		while ((*ant)->links[++x])
		{
			if (has_link((*ant)->links[x], (*ant)->pos[y][0]))
			{
				*t2 = get_link((*ant)->links[x], 0, 1);
				(*ant)->pos[y] = build_pos(ant, (*ant)->pos[y], t2);
				ft_strdel(t2);
			}
			else if (has_link2((*ant)->links[x], (*ant)->pos[y][0]))
			{
				temp = get_link((*ant)->links[x], 0, 0);
				(*ant)->pos[y] = build_pos(ant, (*ant)->pos[y], &temp);
				ft_strdel(&temp);
			}
	//		ft_putendl("links");
	//		ft_putendl("loop x");
	//		print_array((*ant)->pos[y], '\t', 1);
	//		ft_putchar('\n');
		}
//		ft_putendl("loop y");
//		print_array((*ant)->pos[y], '\t', 1);
//		ft_putchar('\n');
	//	ft_putendl("Other side");
		y++;
	}
	(*ant)->pos[y] = NULL;
	(*ant)->path = build_path(ant, (*ant)->path, (*ant)->pos[(*ant)->stin][0]);
}

size_t				find_links(t_ant **ant, size_t x, size_t loc, size_t e)
{
	char	*temp2;
	char	**test;
//
	ft_putendl("broken build?");
	if (!(build(ant, &temp2)))
		return (FAIL);
//	ft_putendl("broken possiblities?");
	create_possibilities(ant, 0, 0, &temp2);
//	ft_putendl("working possiblities");
//	printf("where is the end? %s\n", *(*ant)->pos[(*ant)->edin]);
	test = NULL;
//	ft_putendl("broken loop?");
	while (1)
	{
		test = array_dup((*ant)->path);
//		ft_putendl("Success test");
		printf("%lu\t%lu\tpos: %s\n", (*ant)->msize, e, *(*ant)->pos[e]);
		if (ft_strequ((*ant)->pos[loc][x], (*ant)->pos[e][0]))
		{
			(*ant)->path = build_path(ant, (*ant)->path, (*ant)->pos[e][0]);
			break ;
		}
//		ft_putendl("Success end");
		if (newend(ant, loc, 1, 1) == 1)
			break ;
//		ft_putendl("Success end link");
		map(ant, 0, loc, ft_array_size((*ant)->path) - 1);
//		ft_putendl("Success map");
		loc = location(ant);
//		ft_putendl("Success loc");
		if (!(broken(test, (*ant)->path)))
			return (FAIL);
//		ft_putendl("Success breaker");
	}
//	ft_putendl("loop is fine");
//	free_array2((*ant)->links, ft_array_size((*ant)->links));
//	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	return (PASS);
}
