/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:28:11 by cbester           #+#    #+#             */
/*   Updated: 2018/08/27 10:27:11 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		edit_sted(t_ant **ant, size_t x)
{
	if ((*ant)->stin > x)
		(*ant)->stin--;
	if ((*ant)->edin > x)
		(*ant)->edin--;
}

static void	loc_scrap(t_ant **ant)
{
	size_t	x;
	size_t	y;
	char	*t;

	x = 0;
	while ((*ant)->rooms[x])
	{
		y = 0;
		while ((*ant)->rooms[x][y] != ' ' && (*ant)->rooms[x][y])
			y++;
		t = ft_strsub((*ant)->rooms[x], 0, y);
		free((*ant)->rooms[x]);
		(*ant)->rooms[x] = ft_strdup(t);
		free(t);
		x++;
	}
}

char		***test_build(t_ant **ant)
{
	size_t	x;
	size_t	t;
	char	***new;

	x = 0;
	t = 0;
	while ((*ant)->rooms[t])
		t++;
	if (!(new = (char***)malloc(sizeof(char**) * t + 1)))
		return (NULL);
	while ((*ant)->rooms[x])
	{
		new[x] = ft_strsplit((*ant)->rooms[x], ' ');
		x++;
	}
	new[x] = NULL;
	if ((*ant)->test[0] == NULL)
		free((*ant)->test);
	return (new);
}

size_t		real_room(t_ant **ant, size_t x, size_t y)
{
	size_t	z;

	(*ant)->test = test_build(ant);
	while ((*ant)->test[x])
	{
		y = 1;
		while ((*ant)->test[x][y])
		{
			z = 0;
			while ((*ant)->test[x][y][z])
			{
				if (!ft_isdigit((*ant)->test[x][y][z]))
					return (FAIL);
				z++;
			}
			y++;
		}
		x++;
	}
	loc_scrap(ant);
	return (PASS);
}
