/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 13:29:01 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

size_t	build(t_ant **ant, char **temp)
{
	*temp = NULL;
	if (!((*ant)->path = (char**)malloc(sizeof(char*))))
		return (FAIL);
	(*ant)->path[0] = NULL;
	return (PASS);
}

size_t	broken(char **a, char **b)
{
	size_t	x;

	if (ft_array_size(a) != ft_array_size(b))
		return (PASS);
	x = 0;
	while (a[x])
	{
		if (!ft_strequ(a[x], b[x]))
		{
			free_array(a, ft_array_size(a));
		//	a = NULL;
			return (PASS);
		}
		x++;
	}
	free_array(a, ft_array_size(a));
//	a = NULL;
	return (FAIL);
}

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
	size_t	y;
	size_t	r;

	x = 1;
//	ft_putendl("Before the march");
	if (!ft_strequ((*ant)->path[ft_array_size((*ant)->path) - 1],
				(*ant)->pos[(*ant)->edin][0]))
		return ;
	i = (*ant)->ants;
	r = ft_array_size((*ant)->path);
	y = 1;
//	ft_putendl("Bfore the march");
	while (i)
	{
		marching(ant, x);
		x++;
		i--;
	}
	free_array((*ant)->path, ft_array_size((*ant)->path));
}
