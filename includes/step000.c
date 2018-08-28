/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/08/28 11:24:06 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	*free_a(char *s1, char *s2)
{
	size_t	x;
	size_t	y;
	char	*new;

	if (!(new = (char*)malloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		new[x] = s1[x];
		x++;
	}
	if (s2[y] == '-' && s1[x - 1] == '-')
		y++;
	while (s2[y])
		new[x++] = s2[y++];
	free(s1);
	new[x] = '\0';
	return (new);
}

void	add_space(t_ant **ant)
{
	size_t	x;

	x = 1;
	(*ant)->path[0] = free_a((*ant)->path[0], "-1");
	while ((*ant)->path[x])
	{
		(*ant)->path[x] = free_a((*ant)->path[x], "-0");
		x++;
	}
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

void		final_task(t_ant **ant)
{
	size_t	i;
	size_t	x;
	size_t	y;
	size_t	r;

	x = 1;
	if (!ft_strequ((*ant)->path[ft_array_size((*ant)->path) - 1],
				(*ant)->pos[(*ant)->edin][0]))
		return ;
//	add_space(ant);
	i = (*ant)->ants;
	r = ft_array_size((*ant)->path);
	y = 1;
	while (i)
	{
		marching(ant, x);
		x++;
		i--;
	}
}
