/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/08/21 13:45:29 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

static char	*free_a(char *s1, char *s2)
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

static void	add_space(t_ant **ant)
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

void	march(t_ant **ant, size_t x)
{
	char	*temp;

	if (((*ant)->path[x - 1][ft_strlen((*ant)->path[x - 1]) - 1]) != '0')
	{
		temp = ft_itoa(ft_atoi(&(*ant)->path[x][ft_strlen((*ant)->path[x])
					- 1]) + 1);
		(*ant)->path[x] = free_a((*ant)->path[x], temp);
		(*ant)->path[x - 1] = change((*ant)->path[x], '0');
		free(temp);
	}
	while (x > 1)
	{
		if (((*ant)->path[x][ft_strlen((*ant)->path[x]) - 1]) == '0' &&
				((*ant)->path[x - 1][ft_strlen((*ant)->path[x - 1]) - 1]) != '0')
		{
			(*ant)->path[x] = change((*ant)->path[x], '1');
			(*ant)->path[x - 1] = change((*ant)->path[x - 1], '0');
		//	(*ant)->path[x] = free_a((*ant)->path[x], "1");
		//	(*ant)->path[x - 1] = free_a((*ant)->path[x - 1], "0");
		}
		x--;
	}
	print_array((*ant)->path, '\n', 1);
}

void	marching(t_ant **ant, size_t x)
{
	size_t	i;
	char	*temp;
	size_t	j;

	i = ft_array_size((*ant)->path) - 1;
	while ((*ant)->path[i])
	{
		if ((*ant)->path[i][ft_strlen((*ant)->path[i]) - 1] == '1')
		{
			j = 0;
			while ((*ant)->path[i][j] != '-')
				j++;
			temp = ft_strsub((*ant)->path[j], 0, j);
			printf("%s\n", temp);
			ft_putchar('L');
			ft_putnbr(x);
			ft_putchar('-');
			ft_putstr(temp);
			ft_putchar('\t');
			free(temp);
		}
		i--;
	}
	print_array((*ant)->path, '\n', 1);
}

void		final_task(t_ant **ant)
{
	size_t	i;
	size_t	x;

	x = 1;
	i = ft_array_size((*ant)->path);
	if (ft_strcmp((*ant)->path[ft_array_size((*ant)->path) - 1],
				(*ant)->pos[(*ant)->edin][0]) != 0)
	{
		ft_putstr("Could not find a valid path\n");
		return ;
	}
	add_space(ant);
	while (ft_atoi(&(*ant)->path[0][ft_strlen((*ant)->path[0])])
			!= (int)(*ant)->ants)
	{
		march(ant, i - 1);
//		marching(ant, x);
		x++;
		sleep(1);
	}
	print_array((*ant)->path, '\n', 1);
}
