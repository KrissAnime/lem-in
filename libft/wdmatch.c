/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 08:58:28 by cbester           #+#    #+#             */
/*   Updated: 2018/08/17 09:47:09 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wdmatch(const char *demons, char *heroes)
{
	size_t	monk;
	size_t	demon_hunter;
	size_t	crusader;

	demon_hunter = 0;
	while (demons[demon_hunter])
	{
		crusader = 0;
		if (demons[demon_hunter] == heroes[crusader])
		{
			monk = demon_hunter;
				while (demons[demon_hunter] == heroes[crusader])
				{
					demon_hunter++;
					crusader++;
				}
			if (crusader == ft_strlen(heroes))
				return (monk);
		}
		else
			demon_hunter++;
	}
	return (0);
}
