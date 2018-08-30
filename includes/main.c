/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 14:34:52 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant			*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	if (!(ant->links = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->rooms = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->path = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	if (!(ant->pos = (char***)malloc(sizeof(char**) * 1)))
		return (NULL);
	ant->links[0] = NULL;
	ant->rooms[0] = NULL;
	ant->path[0] = NULL;
	ant->pos[0] = NULL;
	ant->msize = 1;
	ant->lsize = 1;
	ant->psize = 1;
	ant->ants = 0;
	ant->num = 0;
	return (ant);
}

/*static size_t	fail(t_ant **ant, size_t level)
{
	ft_putendl("Bad map");
	free_ant(ant, level);
	return (0);
}*/

int				main(void)
{
	t_ant	*ant;
	size_t	x;

	ant = init();
	x = 0;
	if (!read_map(&ant))
		exit(0);
	//sleep(5);
	ft_putendl("MAP SUCCESS");
	if (!real_room(&ant, 0, 0))
		exit(0);
	ft_putendl("REAL SUCCESS");
	if (!check_path(&ant))
		exit(0);
	ft_putendl("PATH SUCCESS");
	find_links(&ant, 1, ant->stin, ant->edin);
	ft_putendl("MAP SUCCESS");
	x = 0;
	final_task(&ant);
	ft_putendl("MAP SUCCESS");
	free_ant(&ant, 3);
	free(ant);
	return (0);
}
