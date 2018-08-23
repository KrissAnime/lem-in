/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:37:24 by cbester           #+#    #+#             */
/*   Updated: 2018/08/23 09:46:16 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2)
{
	char	*ret;
	size_t	x;
	size_t	y;

	x = -1;
	y = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	if (!(ret = (char*)malloc(y + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[++x])
		ret[x] = s1[x];
	while (s2[x - y])
	{
		ret[x] = s2[x - y];
		x++;
	}
	ret[x] = '\0';
	free(s1);
	free(s2);
	return (ret);
}
