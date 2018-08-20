/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dubcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:09:20 by cbester           #+#    #+#             */
/*   Updated: 2018/08/07 10:56:19 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dubcheck(int *tab, size_t s, int num)
{
	size_t	x;

	x = -1;
	while (++x < s)
	{
		if (x + 1 == s)
			return (1);
		if (tab[x] == num)
			return (0);
	}
	return (1);
}
