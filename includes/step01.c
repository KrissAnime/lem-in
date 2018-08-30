/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:05:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 10:35:10 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	**break_path(t_ant **ant, char **curr)
{
	char	**new;
	size_t	x;

	x = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->psize - 1)))
		return (NULL);
	while (curr[x])
	{
		new[x] = ft_strdup(curr[x]);
		x++;
	}
	new[x] = NULL;
	free_array(curr, ft_array_size(curr));
	(*ant)->psize--;
	return (new);
}

char	**build_path(t_ant **ant, char **curr, char *line)
{
	char	**new;
	size_t	x;

	x = 0;
	(*ant)->psize++;
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->psize)))
		return (NULL);
	while (curr[x])
	{
		new[x] = ft_strdup(curr[x]);
//		ft_strdel(&curr[x]);
		x++;
	}
	new[x++] = ft_strdup(line);
	new[x] = NULL;
//	free(*curr);
//	free(curr);
	free_array(curr, ft_array_size(curr));
	return (new);
}

char	**build_pos(t_ant **ant, char **curr, char **line)
{
	char	**new;
	size_t	x;

	(*ant)->csize++;
	x = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->csize)))
		return (NULL);
	while (curr[x])
	{
		new[x] = ft_strdup(curr[x]);
		x++;
	}
	new[x++] = ft_strdup((*line));
	new[x] = NULL;
//	ft_strdel(line);
	free_array(curr, ft_array_size(curr));
	return (new);
}

char	*room_name(char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != ' ')
		x++;
	return (ft_strsub(s, 0, x));
}

size_t	compare_name(char *test, char *test2, char *name)
{
	if (ft_strequ(test, name) || ft_strequ(test2, name))
	{
		free(test);
		free(test2);
		free(name);
		return (PASS);
	}
	free(name);
	return (FAIL);
}
