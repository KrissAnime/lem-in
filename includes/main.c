/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:57:46 by cbester           #+#    #+#             */
/*   Updated: 2018/08/23 13:43:44 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void		move_start(t_ant **ant, size_t x, size_t k)
{
	char	*temp;
	char	*temp2;

	while ((*ant)->path[0][x] != '-')
		x--;
	if ((*ant)->path[k][ft_strlen((*ant)->path[k]) - 1] == '0')
	{
		temp = ft_strsub((*ant)->path[0], x + 1, ft_strlen((*ant)->path[0]) - x);
		temp2 = ft_itoa(ft_atoi(temp) - 1);
		(*ant)->path[0] = ft_joinfree((*ant)->path[k], temp2);
		(*ant)->path[k] = change((*ant)->path[k], '1');
		free(temp2);
		free(temp);
	}
}

void		move_end(t_ant **ant, size_t x, size_t k)
{
	char	*temp;
	char	*temp2;

	while ((*ant)->path[k][x] != '-')
		x--;
	if ((*ant)->path[k][ft_strlen((*ant)->path[k - 1]) - 1] != '0')
	{
		temp = ft_strsub((*ant)->path[k], x + 1, ft_strlen((*ant)->path[k]) - x);
		temp2 = ft_itoa(ft_atoi(temp) + 1);
		(*ant)->path[k] = ft_joinfree((*ant)->path[k], temp2);
		(*ant)->path[k - 1] = change((*ant)->path[x], '0');
		free (temp2);
		free (temp);
	}
}

t_ant		*init(void)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	if (!(ant->links = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->rooms = (char**)malloc(sizeof(char*) * 1))
		//i	|| !(ant->routes = (char**)malloc(sizeof(char*) * 1))
			|| !(ant->path = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	if (!(ant->test = (char***)malloc(sizeof(char**) * 1))
			|| !(ant->pos = (char***)malloc(sizeof(char**) * 1)))
		return (NULL);
	ant->links[0] = NULL;
	ant->rooms[0] = NULL;
//	ant->routes[0] = NULL;
	ant->path[0] = NULL;
	ant->test[0] = NULL;
	ant->pos[0] = NULL;
	ant->msize = 1;
	ant->lsize = 1;
	ant->ants = 0;
	ant->val = 0;
	ant->num = 0;
	return (ant);
}

static size_t	fail(t_ant *ant, size_t level)
{
	printf("Incorrect Map Data\n");
	free_ant(ant, level);
	return (0);
}

int	main(void)
{
	t_ant	*ant;
	size_t	x;

	ant = init();
	x = 0;
	if (!read_map(&ant))
		return (fail(ant, 0));
	if (!real_room(&ant))
		return (fail(ant, 1));
	if (!check_path(&ant))
		return (fail(ant, 2));
	find_links(&ant, 1, ant->stin, ant->edin);
	final_task(&ant);
	free_ant(ant, 3);
	return (0);
}
