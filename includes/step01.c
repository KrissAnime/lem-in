/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:05:30 by cbester           #+#    #+#             */
/*   Updated: 2018/08/27 09:34:43 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

char	*room_name(char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != ' ')
		x++;
	return (ft_strsub(s, 0, x));
}

size_t	compare_name(char *test, char *test2, char *name)
{
	if (ft_strequ(test, name) || ft_strequ(test2, name))
	{
		free(test);
		free(test2);
		free(name);
		return (PASS);
	}
	free(name);
	return (FAIL);
}
