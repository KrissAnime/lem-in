/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 06:32:04 by cbester           #+#    #+#             */
/*   Updated: 2018/08/17 11:21:53 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int	has_link2(char *link, char *name)
{
	int		y;
	int		z;
	char	*temp;

	z = 0;
	while (link[z] != '-')
		z++;
	temp = ft_strsub(link, z + 1, ft_strlen(link));
	y = ft_strcmp(temp, name);
//	printf("Testing link 2: %s\tTesting name: %s\n", temp, name);
	free(temp);
	return (y);
}

int	has_link(char *link, char *name)
{
	int		x;
	int		y;
	char	*temp;

	x = 0;
	while (link[x] != '-')
		x++;
	temp = ft_strsub(link, 0, x);
	y = ft_strcmp(temp, name);
//	printf("Testing link 1: %s\tTesting name: %s\n", temp, name);
	free(temp);
	return (y);
}

int	real_link(t_ant **ant, char *name, size_t x)
{
	char	*num;

	(*ant)->num = 0;
	while ((*ant)->links[x])
	{
		if (has_link((*ant)->links[x], name) == 0
				|| has_link2((*ant)->links[x], name) == 0)
			(*ant)->num++;
		x++;
	}
	num = ft_itoa((*ant)->num);
//	printf("Number of links: %s\n", num);
//	printf("Room before-> %s\n", (*ant)->rooms[rnum]);
//	printf("Room after-> %s\n", (*ant)->rooms[rnum]);
	free(num);
	if((*ant)->num == 0)
		return (NO_LINK);
	return (IS_LINK);
}

int	check_path(t_ant **ant)
{
	size_t	x;
	char	*num;

	x = 0;
//	printf("RAP\t");
	while ((*ant)->rooms[x])
	{
//		if (ft_strcmp("3", (*ant)->rooms[x]) == 0)
//			printf("found bugged room, links: %s\t%lu\n", (*ant)->rooms[x], (*ant)->num);
		if ((real_link(ant, (*ant)->rooms[x], 0)) == NO_LINK)
		{
			if ((*ant)->stin == x || (*ant)->edin == x)
				return (FAIL);
			(*ant)->rooms = destroyer(ant, (*ant)->rooms, x);
//			printf("current start: %lu and end: %lu\n", (*ant)->stin, (*ant)->edin);
		}
		else
		{
			num = ft_itoa((*ant)->num);
			(*ant)->rooms[x] = room_changer(num, (*ant)->rooms[x], 0);
			free(num);
			x++;
		}
//		if (ft_strcmp("5 9 3", (*ant)->rooms[x]) == 0)
//			printf("found unlinked room, links: %lu\n", (*ant)->num);
//		printf("RAP\t");
	}
//	printf("TAP\n");
	return (PASS);
}
