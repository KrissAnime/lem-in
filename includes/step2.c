/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 08:28:11 by cbester           #+#    #+#             */
/*   Updated: 2018/08/21 13:44:59 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char		*change(char *s, char b)
{
	char	*new;
	size_t	x;
	size_t	y;

	y = ft_strlen(s);
	if (!(new = (char*)malloc(y)))
		return (NULL);
	x = 0;
	while (x < y - 1)
	{
		new[x] = s[x];
		x++;
	}
	new[x++] = b;
	new[x] = '\0';
	free(s);
	return (new);
}

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
	char	*t;

	x = 0;
	while ((*ant)->rooms[x])
	{
		t = ft_strsub((*ant)->rooms[x], 0, ft_findchar((*ant)->rooms[x], ' '));
		free((*ant)->rooms[x]);
		(*ant)->rooms[x] = ft_strdup(t);
		free(t);
		x++;
	}
}

char		***test_build(t_ant **ant)
{
	size_t	x;
	char	***new;

	x = 0;
	if (!(new = (char***)malloc(sizeof(char**) * (*ant)->msize)))
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

size_t		real_room(t_ant **ant)
{
	size_t	x;
	size_t	y;

	x = 0;
	(*ant)->test = test_build(ant);
//	printf("RAP\t");
	while ((*ant)->test[x])
	{
		y = x + 1;
		while ((*ant)->test[y])
		{
			if (ft_strcmp((*ant)->test[x][1], (*ant)->test[y][1]) == 0
					&& ft_strcmp((*ant)->test[x][2], (*ant)->test[y][2]) == 0)
				return (FAIL);
			y++;

		}
//		printf("TAP\t");
		x++;
	}
	loc_scrap(ant);
//	printf("TAP\n");
	return (PASS);
}
