/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 13:45:08 by cbester          ###   ########.fr       */
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
	return (0);
}

static size_t	final_free(t_ant **ant, char *s)
{
	size_t	x;

	x = 0;
//	ft_putendl("Here we are");
	ft_putendl(s);
//	printf("%lu\n", (*ant)->msize);
	while (x < (*ant)->msize - 1 && (*ant)->pos[x])
	{
//		print_array((*ant)->pos[x], '\n', 1);
//		ft_putchar('\n');
		free_array((*ant)->pos[x], ft_array_size((*ant)->pos[x]));
		x++;
	}
	free((*ant)->pos);
//	free_array((*ant)->path, ft_array_size((*ant)->path));
	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	free_array((*ant)->links, ft_array_size((*ant)->links));
	return (0);
}

int				main(void)
{
	t_ant	*ant;

	ant = init();
	if (!read_map(&ant))
		return (fail(&ant, "Unable to read map"));
	ft_putendl("Done reading");
	if (!real_room(&ant, 0, 0))
		return (fail(&ant, "Room error detected"));
	ft_putendl("Done verifying");
	if (!check_path(&ant))
		return (fail(&ant, "Path broken"));
	ft_putendl("Done checking path");
	if (!(ant->pos = (char***)malloc(sizeof(char**) * ant->msize)))
		return (fail(&ant, "Possible route malloc fail"));
	ant->pos[0] = NULL;
//	ft_putendl("Broken");
	if (!find_links(&ant, 1, ant->stin, ant->edin))
	{
		(final_free(&ant, "Failed to connect to end"));
		free(ant);
		return (0);
	}
//	ft_putendl("Broken Task?");
	final_task(&ant);
//	ft_putendl("Broken Free?");
	final_free(&ant, "Done");
//	free_ant(&ant, 3);
//	sleep(5);
	free(ant);
	return (0);
}
