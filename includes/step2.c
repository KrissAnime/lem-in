/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:28:11 by cbester           #+#    #+#             */
/*   Updated: 2018/09/03 11:36:51 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void			edit_sted(t_ant **ant, size_t x)
{
	if ((*ant)->stin > x)
		(*ant)->stin--;
	if ((*ant)->edin > x)
		(*ant)->edin--;
}

static void		loc_scrap(t_ant **ant)
{
	size_t	x;
	size_t	y;
	char	*t;

	x = 0;
	t = NULL;
	while ((*ant)->rooms[x])
	{
		y = 0;
		while ((*ant)->rooms[x][y] != ' ' && (*ant)->rooms[x][y])
			y++;
		t = ft_strsub((*ant)->rooms[x], 0, y);
		free((*ant)->rooms[x]);
		(*ant)->rooms[x] = ft_strdup(t);
		ft_strdel(&t);
		x++;
	}
}

size_t			real_room(t_ant **ant, size_t x, size_t y)
{
	while ((*ant)->rooms[x])
	{
		y = 0;
		while ((*ant)->rooms[x][y] != ' ' && (*ant)->rooms[x][y])
			y++;
		while ((*ant)->rooms[x][++y])
			if (!ft_isdigit((*ant)->rooms[x][y]) && (*ant)->rooms[x][y] != ' ')
				return (FAIL);
		x++;
	}
	loc_scrap(ant);
	return (PASS);
}
