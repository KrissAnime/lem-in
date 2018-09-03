/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:12:18 by cbester           #+#    #+#             */
/*   Updated: 2018/09/03 09:02:31 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
				free_array(str, i);
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
	if (ft_strlen(s) == 0)
	{
		if (!(str = (char**)malloc(sizeof(char*) * 2)))
			return (NULL);
		str[0] = ft_strdup("");
		str[1] = NULL;
		return (str);
	}
	if (!(str = (char**)malloc(sizeof(char*) * (ft_numsplit(s, c) + 1))))
		return (NULL);
	ft_createsplit(str, s, i, c);
	return (str);
}
