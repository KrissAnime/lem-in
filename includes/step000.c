/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/08/27 09:34:28 by cbester          ###   ########.fr       */
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
	char	*temp;

	temp = ft_itoa((*ant)->ants);
	x = 1;
	(*ant)->path[0] = free_a((*ant)->path[0], "-");
	(*ant)->path[0] = free_a((*ant)->path[0], temp);
	free(temp);
	while ((*ant)->path[x])
	{
		(*ant)->path[x] = free_a((*ant)->path[x], "-0");
		x++;
	}
}

void	marching(t_ant **ant, size_t x)
{
	size_t	i;
	size_t	k;
	char	*name;

	i = 1;
	while ((*ant)->path[i])
	{
		k = 0;
		while ((*ant)->path[i][k] != '-')
			k++;
		ft_putchar('L');
		ft_putnbr(x);
		ft_putchar('-');
		name = ft_strsub((*ant)->path[i], 0, k);
		ft_putstr(name);
		ft_putchar('\n');
		i++;
		free(name);
	}
}

void		final_task(t_ant **ant)
{
	size_t	i;
	size_t	x;

	x = 1;
	if (!ft_strequ((*ant)->path[ft_array_size((*ant)->path) - 1],
				(*ant)->pos[(*ant)->edin][0]))
		return ;
	add_space(ant);
	i = (*ant)->ants;
	while (i)
	{
		marching(ant, x);
		x++;
		i--;
	}
}
