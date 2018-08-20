/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:12:18 by cbester           #+#    #+#             */
/*   Updated: 2018/08/16 09:00:31 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_destroy(char **str, size_t i)
{
	while (i)
	{
		ft_strdel(&str[i]);
		i--;
	}
	ft_strdel(str);
}

static int	ft_numsplit(char const *s, char c)
{
	size_t	i;
	int		x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			x++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (x);
}

static char	**ft_createsplit(char **str, char const *s, size_t i, char c)
{
	size_t	x;
	size_t	j;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c)
		{
			j = x;
			while (s[x] != c && s[x] != '\0')
				x++;
			if (!(str[i] = ft_strsub(s, j, x - j)))
			{
				ft_destroy(str, i);
				return (NULL);
			}
			i++;
		}
		else
			x++;
	}
	str[i] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_numsplit(s, c)))))
		return (NULL);
	ft_createsplit(str, s, i, c);
	return (str);
}
