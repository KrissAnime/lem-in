/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <cbester@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/09/17 09:29:54 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

int		manage_data(t_ant **ant, size_t x, int ret, int line)
{
	while ((*ant)->map[x])
	{
		if (x == 0)
		{
			if (!(get_ants(&(*ant)->map[x], ant, 0)))
				error_msg("Invalid ant number");
			x++;
		}
		line = line_check(&(*ant)->map[x], ant);
		ret = map_handler(ant, &x, line);
		if (ret == FAIL || x == FAIL)
			return (FAIL);
		x++;
	}
	return (PASS);
}

size_t	build(t_ant **ant, char **temp)
{
	*temp = NULL;
	if (!((*ant)->path = (char**)malloc(sizeof(char*))))
		error_msg("Path array fail");
	(*ant)->path[0] = NULL;
	return (PASS);
}

size_t	broken(char **a, char **b)
{
	size_t	x;

	if (ft_array_size(a) != ft_array_size(b))
	{
		free_array(a, ft_array_size(a));
		a = NULL;
		return (PASS);
	}
	x = 0;
	while (a[x])
	{
		if (!ft_strequ(a[x], b[x]))
		{
			free_array(a, ft_array_size(a));
			a = NULL;
			return (PASS);
		}
		x++;
	}
	free_array(a, ft_array_size(a));
	a = NULL;
	return (FAIL);
}

void	marching(t_ant **ant, size_t x)
{
	size_t	i;

	i = 1;
	while ((*ant)->path[i])
	{
		ft_putchar('L');
		ft_putnbr(x);
		ft_putchar('-');
		ft_putstr((*ant)->path[i]);
		ft_putchar('\n');
		i++;
	}
}

void	final_task(t_ant **ant)
{
	size_t	i;
	size_t	x;

	x = 1;
	if (!ft_strequ((*ant)->path[ft_array_size((*ant)->path) - 1],
				(*ant)->pos[(*ant)->edin][0]))
		return ;
	i = (*ant)->ants;
	print_array((*ant)->map, '\n', 1);
	ft_putchar('\n');
	free_array((*ant)->map, ft_array_size((*ant)->map));
	while (i)
	{
		marching(ant, x);
		x++;
		i--;
	}
	free_array((*ant)->path, ft_array_size((*ant)->path));
	final_free(ant, "Success!");
}
