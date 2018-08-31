/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:02:06 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 14:33:37 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**array_dup(char **s)
{
	char	**ret;
	size_t	x;

	if (!s)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * ft_array_size(s) + 1)))
		return (NULL);
	x = 0;
	while (s[x])
	{
		ret[x] = ft_strdup(s[x]);
		x++;
	}
	ret[x] = s[x];
	return (ret);
}
