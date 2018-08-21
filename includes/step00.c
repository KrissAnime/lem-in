/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:11:59 by cbester           #+#    #+#             */
/*   Updated: 2018/08/21 10:02:31 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

size_t	isitover(t_ant **ant)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (*ant)->msize - 1)
	{
		x = 1;
		while ((*ant)->pos[y][x])
		{
			if (y == (*ant)->edin)
				return (0);
			if (ft_findchar((*ant)->pos[y][x], '-') == 0)
				return (1);
			
			x++;
		}
		y++;
	}
	return (0);
}

size_t	newend(t_ant **ant, size_t loc, size_t x, size_t y)
{
//	printf("Testing the end\n");
	while ((*ant)->pos[loc][y])
	{
		while ((*ant)->pos[(*ant)->edin][x])
		{
		//	printf("%s\t%s\n", (*ant)->pos[loc][y], (*ant)->pos[(*ant)->edin][x]);
			if (ft_strcmp((*ant)->pos[loc][y],
						(*ant)->pos[(*ant)->edin][x]) == 0)
			{
		//		printf("Totally valid\n");
				(*ant)->path = ft_array_grow((*ant)->path,
						(*ant)->pos[(*ant)->edin][x]);
				(*ant)->path = ft_array_grow((*ant)->path,
						(*ant)->pos[(*ant)->edin][0]);
		//		print_array((*ant)->path, '\n', 1);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	*get_name(t_ant **ant, size_t i)
{
	size_t	x;
	char	*name;

	x = 0;
	while ((*ant)->rooms[i][x] != ' ')
		x++;
	name = ft_strsub((*ant)->rooms[i], 0, x);
	return (name);
}

char	*pass(char *room)
{
	char	*new;
	size_t	x;

	if (!(new = (char*)malloc(ft_strlen(room) + 1)))
		return (NULL);
	x = 0;
	while (room[x])
	{
		new[x] = room[x];
		x++;
	}
	new[x++] = '-';
	free(room);
	return (new);
}

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
