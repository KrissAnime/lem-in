/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:35:10 by cbester           #+#    #+#             */
/*   Updated: 2018/08/20 11:33:28 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	free_array_2(char ***array, size_t x)
{
	while (array[x])
	{
		free(array[x][2]);
		free(array[x][1]);
		free(array[x][0]);
		free(array[x--]);
	}
	free(array);
}

void	free_ant(t_ant *ant)
{
	free_array(ant->links, ft_array_size(ant->links));
	free_array(ant->rooms, ft_array_size(ant->rooms));
	free_array(ant->routes, ft_array_size(ant->routes));
//	free_array(ant->path, ft_array_size(ant->path));
	if (ant->test[0] != NULL)
		free_array_2(ant->test, ant->msize);
	free(ant);
}
