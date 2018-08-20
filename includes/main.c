/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/17 11:09:49 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant		*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	if (!(ant->links = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->rooms = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->routes = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->path = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	if (!(ant->test = (char***)malloc(sizeof(char**) * 1))
			|| !(ant->pospath = (char***)malloc(sizeof(char**) * 1)))
		return (NULL);
	ant->links[0] = NULL;
	ant->rooms[0] = NULL;
	ant->routes[0] = NULL;
	ant->path[0] = NULL;
	ant->test[0] = NULL;
	ant->pospath[0] = NULL;
	ant->msize = 1;
	ant->lsize = 1;
	ant->ants = 0;
	ant->val = 0;
	ant->num = 0;
	return (ant);
}

static size_t	fail(t_ant *ant)
{
	printf("Incorrect Map Data\n");
	free_ant(ant);
	return (0);
}

int	main(void)
{
	t_ant	*ant;
	size_t	x;
	size_t	y;

	ant = init();
	x = 0;
//	printf("ants before map: %lu\n", ant->ants);
	if (!read_map(&ant))
		return (fail(ant));
//	printf("mapped rooms\n");
	while (ant->rooms[x])
		printf("%s\n", ant->rooms[x++]);
//	printf("linked rooms\n");
	x = 0;
	while (ant->links[x])
		printf("%s\n", ant->links[x++]);
	printf("Start room: %lu\t End room: %lu\n", ant->stin, ant->edin);
	if (!real_room(&ant))
		return (fail(ant));
	y = 0;
	printf("Room data modified to remove co-ordinadtes after room validation\n");
	while (ant->rooms[y])
		printf("%s\n", ant->rooms[y++]);
	if (!check_path(&ant))
		return (fail(ant));
	printf("Data modified to add number of links for each room\n");
	x = 0;
	while (ant->rooms[x])
		printf("%s\n", ant->rooms[x++]);
	printf("current msize: %lu\n", ant->msize);
//	printf("location of ' ' in '1 23 3' is: %lu\n", wdmatch("1 23 3", "23"));
//	printf("3d array for validating room coordinates\n");
//	printf("%s\n", ant->test[1][1]);
/*	while (ant->test[y])
	{
		x = 0;
		while (ant->test[y][x])
			printf("%s\t", ant->test[y][x++]);
		printf("\n");
		y++;
	}*/
/*	printf("Data modified to delete unlinked rooms\n");
	while (ant->rooms[x])
		printf("%s\n", ant->rooms[x++]);
	free_ant(ant);*/
	//real_link(&ant, ant->rooms[ant->stin], 2);
	return (0);
}
