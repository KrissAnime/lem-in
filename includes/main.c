/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 14:15:06 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant			*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	if (!(ant->links = (char**)malloc(sizeof(char*)))
			|| !(ant->rooms = (char**)malloc(sizeof(char*))))
		return (NULL);
	ant->links[0] = NULL;
	ant->rooms[0] = NULL;
	ant->msize = 1;
	ant->lsize = 1;
	ant->psize = 1;
	ant->ants = 0;
	ant->num = 0;
	return (ant);
}

static size_t	fail(t_ant **ant, char *s)
{
	ft_putendl(s);
	free_ant(ant);
	exit(0);
}

static size_t	final_free(t_ant **ant, char *s)
{
	size_t	x;

	x = 0;
	ft_putendl(s);
	while (x < (*ant)->msize - 1 && (*ant)->pos[x])
	{
		free_array((*ant)->pos[x], ft_array_size((*ant)->pos[x]));
		x++;
	}
	free((*ant)->pos);
	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	free_array((*ant)->links, ft_array_size((*ant)->links));
	free(*ant);
	exit(0);
}

int				main(void)
{
	t_ant	*ant;

	ant = init();
	if (!read_map(&ant))
		fail(&ant, "Unable to read map");
	if (!real_room(&ant, 0, 0))
		fail(&ant, "Room error detected");
	if (!check_path(&ant))
		fail(&ant, "Path broken");
	if (!(ant->pos = (char***)malloc(sizeof(char**) * ant->msize)))
		fail(&ant, "Possible route malloc fail");
	ant->pos[0] = NULL;
	if (!find_links(&ant, 1, ant->stin, ant->edin))
	{
		(final_free(&ant, "Failed to connect to end"));
		exit(0);
	}
	final_task(&ant);
	final_free(&ant, "Done");
	exit(0);
}
