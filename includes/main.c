/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <cbester@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/09/17 09:30:41 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

t_ant			*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		error_msg("Ant struct malloc fail");
	ant->msize = 1;
	ant->rsize = 1;
	ant->lsize = 1;
	ant->psize = 1;
	ant->ants = 0;
	ant->num = 0;
	ant->stin = -1;
	ant->edin = -1;
	return (ant);
}

void			final_free(t_ant **ant, char *s)
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
	{
		ft_putendl("Data error detected");
		free(ant);
		exit(1);
	}
	if ((int)ant->stin < 0 || (int)ant->edin < 0)
		error_msg("No start or end room");
	if (!real_room(&ant, 0, 0))
		error_msg("Room verefication failed");
	if (!check_path(&ant))
		error_msg("Path check fail");
	if (!(ant->pos = (char***)malloc(sizeof(char**) * ant->msize)))
		error_msg("Pos route malloc fail");
	ant->pos[0] = NULL;
	if (!find_links(&ant, 1, ant->stin, ant->edin))
		error_msg("Failed to connect to end");
	else
		final_task(&ant);
	return (0);
}
