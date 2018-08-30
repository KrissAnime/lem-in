/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:56:05 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 10:27:06 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	*room_changer(char *mod, char *old, size_t x)
{
	char	*new;
	size_t	i;

	if (!(new = (char*)malloc(ft_strlen(old) + ft_strlen(mod) + 4)))
		return (NULL);
	i = 0;
	while (old[x])
	{
		new[i] = old[x];
		i++;
		x++;
	}
	new[i++] = ' ';
	new[i++] = 'l';
	new[i++] = '-';
	x = 0;
	while (mod[x])
		new[i++] = mod[x++];
	new[i] = '\0';
	free(old);
	return (new);
}

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
	free_array(test, ft_array_size(test));
//	sleep(3);
	if (i != 3)
		return (FAIL);
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
	new[x++] = ft_strdup(line);
	new[x] = NULL;
	free_array(curr, ft_array_size(curr));
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
	new[x] = NULL;
	(*ant)->msize--;
	free_array(curr, ft_array_size(curr));
	return (new);
}
