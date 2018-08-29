/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/28 12:05:51 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant			*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	if (!(ant->links = (char**)malloc(sizeof(char*)))
			|| !(ant->rooms = (char**)malloc(sizeof(char*)))
			|| !(ant->path = (char**)malloc(sizeof(char*))))
		return (NULL);
	if (!(ant->test = (char***)malloc(sizeof(char**)))
			|| !(ant->pos = (char***)malloc(sizeof(char**))))
		return (NULL);
	ant->links[0] = NULL;
	ant->rooms[0] = NULL;
	ant->path[0] = NULL;
	ant->test[0] = NULL;
	ant->pos[0] = NULL;
	ant->msize = 1;
	ant->lsize = 1;
	ant->psize = 2;
	ant->ants = 0;
	ant->num = 0;
	return (ant);
}

static size_t	fail(t_ant **ant, size_t level)
{
	ft_putendl("Bad map");
	free_ant(ant, level);
	return (0);
}

int				main(void)
{
	t_ant	*ant;
	size_t	x;

	ant = init();
	x = 0;
	if (!read_map(&ant))
		return (fail(&ant, 0));
	if (!real_room(&ant, 0, 1))
		return (fail(&ant, 1));
	if (!check_path(&ant))
		return (fail(&ant, 2));
	free_big_array(ant->test);
	find_links(&ant, 1, ant->stin, ant->edin);
	x = 0;
	final_task(&ant);
	free_ant(&ant, 3);
	free(ant);
	return (0);
}
