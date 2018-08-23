/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step000.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:28:49 by cbester           #+#    #+#             */
/*   Updated: 2018/08/23 12:25:33 by cbester          ###   ########.fr       */
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
	size_t	y;
	size_t	k;

	k = x;
	y = ft_strlen((*ant)->path[x - 1]);
//	printf("Bug tracker 01\n");
	if (((*ant)->path[x - 1][y - 1]) != '0')
		move_end(ant, y - 1, k);
	x--;
//	printf("Bug tracker 02\n");
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
//	printf("Bug tracker 03\n");
	y = ft_strlen((*ant)->path[0]);
	if ((*ant)->path[0][ft_strlen((*ant)->path[0]) - 1] != '0')
		move_start(ant, y - 1, 1);
//	print_array((*ant)->path, '\n', 1);
//	sleep(5);
//	printf("Bug tracker 04\n");
}

void	marching(t_ant **ant, size_t x)
{
	size_t	i;
	size_t	k;
	char	*name;

	i = 1;
//	printf("TEsting\n");
	ft_putchar('\n');
	print_array((*ant)->path, '\t', 1);
	ft_putchar('\n');
	while ((*ant)->path[i])
	{
		k = 0;
		//printf("TEsting\n");
		while ((*ant)->path[i][k] != '-')
			k++;
		//	printf("%s\n", temp);
		ft_putchar('L');
		ft_putnbr(x);
		ft_putchar('-');
		name = ft_strsub((*ant)->path[i], 0, k);
	//	printf("Testing what is name: %s\n", name);
	//	sleep(1);
		ft_putstr(name);
		ft_putchar('\n');
		i++;
		free(name);
	}
//	sleep(3);
//	print_array((*ant)->path, '\n', 1);
//	sleep(3);
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
//	sleep(1);
//	print_array((*ant)->path, '\n', 1);
//	sleep(1);
	i = (*ant)->ants;
	while (i)
	{
	//	march(ant, i - 1);
	//	sleep(1);
		marching(ant, x);
		x++;
		i--;
	//	sleep(1);
	}
	//print_array((*ant)->path, '\n', 1);
}
