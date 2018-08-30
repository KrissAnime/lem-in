/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:12:31 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 10:11:19 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

/*
**	Room format and link verification are in step0.c
*/

size_t	line_check(char **line, t_ant **ant)
{
	if (ft_strequ((*line), "##start"))
		return (START);
	else if (ft_strequ((*line), "##end"))
		return (END);
	else if ((*line)[0] == '#' && (*line)[1] != '#')
		return (COMMENT);
	else if ((*line)[0] == '#' && (*line)[1] == '#')
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
		{
			free((*line));
			return (FAIL);
		}
	}
	size = ft_atoi((*line));
	num = ft_itoa(size);
	if (!ft_strequ((*line), num) || size <= 0)
	{
		free((*line));
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

int		read_room(t_ant **ant, char *line, size_t room)
{
	ft_strdel(&line);
	get_next_line(0, &line);
	if (room == 0 && room_format(line, 1))
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, line)))
		{
			free(line);
			return (FAIL);
		}
		(*ant)->stin = (*ant)->msize - 2;
	}
	if (room == 1 && room_format(line, 1))
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, line)))
		{
			free(line);
			return (FAIL);
		}
		(*ant)->edin = (*ant)->msize - 2;
	}
	ft_strdel(&line);
	return (PASS);
}

int		map_handler(t_ant **ant, char **line, size_t x)
{
	if (x == START && !read_room(ant, (*line), 0))
		return (FAIL);
	else if (x == COMMENT)
		return (PASS);
	else if (x == END && !read_room(ant, (*line), 1))
		return (FAIL);
	else if (x == ROOM)
	{
		if (!((*ant)->rooms = builder(ant, (*ant)->rooms, (*line))))
			return (FAIL);
	}
	else if (x == LINK)
	{
		if (!((*ant)->links = build_link(ant, (*ant)->links, (*line))))
			return (FAIL);
	}
	else if (x != START && x != END && x != COMMENT && x != LINK && x != ROOM)
		return (FAIL);
	return (PASS);
}

int		read_map(t_ant **ant)
{
	char	*line;
	size_t	x;
	size_t	k;
	int		ret;

	line = NULL;
	k = 0;
	get_next_line(0, &line);
	if (!(get_ants(&line, ant, 0)))
		return (FAIL);
	free(line);
	while (get_next_line(0, &line))
	{
		k++;
		x = line_check(&line, ant);
		ret = map_handler(ant, &line, x);
		if (ret == FAIL && k < 4)
			return (FAIL);
		if (ret == FAIL && k >= 4)
			break ;
	}
	ft_strdel(&line);
	return (PASS);
}
