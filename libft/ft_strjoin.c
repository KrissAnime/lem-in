/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:13:03 by cbester           #+#    #+#             */
/*   Updated: 2018/06/15 09:40:58 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	char	*str;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	x = 0;
	while (x < ft_strlen(s1))
	{
		str[x] = s1[x];
		x++;
	}
	while (x - ft_strlen(s1) < ft_strlen(s2))
	{
		str[x] = s2[x - ft_strlen(s1)];
		x++;
	}
	str[x] = '\0';
	return (str);
}
