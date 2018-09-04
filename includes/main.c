/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/09/04 14:09:51 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant			*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ant->msize = 1;
	ant->lsize = 1;
	ant->psize = 1;
	ant->ants = 0;
	ant->num = 0;
	ant->stin = -1;
	ant->edin = -1;
	return (ant);
}

static size_t	fail(t_ant **ant, char *s)
{
	ft_putendl(s);
	free_ant(ant);
	free(ant);
	exit(1);
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
	exit(1);
}

int				main(void)
{
	t_ant	*ant;

	ant = init();
	if (!read_map(&ant, 0, 0, 0))
	{
		ft_putendl("Data error detected");
		exit(0);
	}
	if ((int)ant->stin < 0 || (int)ant->edin < 0)
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
		exit(1);
	}
	final_task(&ant);
	final_free(&ant, "Done");
	sleep(25);
	exit(1);
}
