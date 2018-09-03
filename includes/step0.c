/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:56:05 by cbester           #+#    #+#             */
/*   Updated: 2018/09/03 11:30:48 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

size_t	check_link(char *line, size_t i, size_t k, t_ant **ant)
{
	char	*test;
	char	*test2;

	test = get_link(line, i, 0);
	test2 = get_link(line, i, 1);
	while ((*ant)->rooms[k])
	{
		if (compare_name(test, test2, room_name((*ant)->rooms[k])))
			return (PASS);
		k++;
	}
	free(test);
	free(test2);
	return (FAIL);
}

size_t	room_format(char *line, size_t i)
{
	char	**test;
	char	*val;

	if (!(test = ft_strsplit(line, ' ')))
		return (FAIL);
	while (test[i])
	{
		val = ft_itoa(ft_atoi(test[i]));
		if (!ft_strequ(val, test[i]))
		{
			free_array(test, ft_array_size(test));
			free(val);
			return (FAIL);
		}
		free(val);
		i++;
	}
	if (i != 3)
	{
		free_array(test, ft_array_size(test));
		return (FAIL);
	}
	free_array(test, ft_array_size(test));
	return (PASS);
}

char	**builder(t_ant **ant, char **curr, char *line)
{
	char	**new;
	size_t	x;

	(*ant)->msize++;
	x = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->msize)))
		return (NULL);
	while (curr[x])
	{
		new[x] = ft_strdup(curr[x]);
		x++;
	}
	free_array(curr, ft_array_size(curr));
	new[x++] = ft_strdup(line);
	new[x] = NULL;
	return (new);
}

char	**destroyer(t_ant **ant, char **curr, size_t target)
{
	char	**new;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	edit_sted(ant, x);
	if (!(new = (char**)malloc(sizeof(char*) * (*ant)->msize - 1)))
		return (NULL);
	if ((*ant)->msize >= 2)
	{
		while (curr[y])
		{
			if (y == target)
				y++;
			else
				new[x++] = ft_strdup(curr[y++]);
		}
	}
	free_array(curr, ft_array_size(curr));
	new[x] = NULL;
	(*ant)->msize--;
	return (new);
}
