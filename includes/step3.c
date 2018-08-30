/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 06:32:04 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 14:31:02 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	*get_link(char *link, size_t x, size_t code)
{
	char	*link_name;

	while (link[x] != '-')
		x++;
	if (code == 0)
		link_name = ft_strsub(link, 0, x);
	else
		link_name = ft_strsub(link, x + 1, ft_strlen(link) - x);
	return (link_name);
}

int		has_link2(char *link, char *name)
{
	int		y;
	char	*temp;

	temp = get_link(link, 0, 1);
	y = ft_strequ(temp, name);
	free(temp);
	return (y);
}

int		has_link(char *link, char *name)
{
	int		y;
	char	*temp;

	temp = get_link(link, 0, 0);
	y = ft_strequ(temp, name);
	free(temp);
	return (y);
}

int		real_link(t_ant **ant, char *name, size_t x)
{
	(*ant)->num = 0;
	while ((*ant)->links[x])
	{
		if (has_link((*ant)->links[x], name)
				|| has_link2((*ant)->links[x], name))
			(*ant)->num++;
		x++;
	}
	if ((*ant)->num == 0)
		return (NO_LINK);
	return (IS_LINK);
}

int		check_path(t_ant **ant)
{
	size_t	x;

	x = 0;
	while ((*ant)->rooms[x])
	{
		if ((real_link(ant, (*ant)->rooms[x], 0)) == NO_LINK)
		{
			if ((*ant)->stin == x || (*ant)->edin == x)
			{
				ft_putendl("No link to end or beginning!");
				return (FAIL);
			}
			(*ant)->rooms = destroyer(ant, (*ant)->rooms, x);
		}
		else
			x++;
	}
	return (PASS);
}
