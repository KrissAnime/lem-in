/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:12:31 by cbester           #+#    #+#             */
/*   Updated: 2018/09/06 08:27:29 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
**	Room format and link verification are in step0.c
*/

size_t	line_check(char **line, t_ant **ant)
{
	if ((*line)[0] == 'L')
		return (FAIL);
	else if (ft_strequ((*line), "##start"))
		return (START);
	else if (ft_strequ((*line), "##end"))
		return (END);
	else if ((*line)[0] == '#')
		return (COMMENT);
	else if (room_format((*line), 1))
		return (ROOM);
	else if (check_link((*line), 0, 0, ant))
		return (LINK);
	return (FAIL);
}

/*
**	Verifies that the first line is number of ants and that there are ants to
**	move
*/

int		get_ants(char **line, t_ant **ant, size_t i)
{
	char	*num;
	int		size;

	while ((*line)[i])
	{
		if (!ft_isdigit((*line)[i++]))
			return (FAIL);
	}
	size = ft_atoi((*line));
	num = ft_itoa(size);
	if (!ft_strequ((*line), num) || size <= 0)
	{
		free(num);
		return (FAIL);
	}
	free(num);
	(*ant)->ants = (size_t)size;
	return (PASS);
}

/*
**	Manages the start and end rooms, also saves their indexes in within the
**	2D array
*/

int		read_room(t_ant **ant, size_t room, size_t *x)
{
	*x += 1;
	if (room == 0 && room_format((*ant)->map[*x], 1))
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, (*ant)->map[*x])))
			return (FAIL);
		(*ant)->stin = (*ant)->msize - 2;
		return (PASS);
	}
	if (room == 1 && room_format((*ant)->map[*x], 1))
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, (*ant)->map[*x])))
			return (FAIL);
		(*ant)->edin = (*ant)->msize - 2;
		return (PASS);
	}
	return (FAIL);
}

int		map_handler(t_ant **ant, size_t *x, int line)
{
	if (line == START && !read_room(ant, 0, x))
		return (FAIL);
	else if (line == COMMENT)
		return (PASS);
	else if (line == END && !read_room(ant, 1, x))
		return (FAIL);
	else if (line == ROOM)
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, (*ant)->map[*x])))
			return (FAIL);
	}
	else if (line == LINK)
	{
		if (!((*ant)->links = build_link(ant, (*ant)->links, (*ant)->map[*x])))
			return (FAIL);
	}
	else if (line != START && line != END && line != COMMENT && line != LINK
			&& line != ROOM)
		return (FAIL);
	return (PASS);
}

int		read_map(t_ant **ant)
{
	char	*line;

	line = NULL;
	if (!((*ant)->map = (char**)malloc(sizeof(char*))))
		return (FAIL);
	(*ant)->map[0] = NULL;
	while (get_next_line(0, &line))
	{
		(*ant)->map = map_read(ant, line);
		ft_strdel(&line);
	}
	free(line);
	if (ft_array_size((*ant)->map) < 4)
	{
		free_array((*ant)->map, ft_array_size((*ant)->map));
		return (FAIL);
	}
	if (!(room_links(ant)))
		return (FAIL);
	return (manage_data(ant, 0, 0, 0));
}
