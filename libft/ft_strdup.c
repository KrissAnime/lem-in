/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:14 by cbester           #+#    #+#             */
/*   Updated: 2018/09/03 10:52:30 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		if (!(s2 = (char*)malloc(1)))
			return (NULL);
		s2[0] = '\0';
		return (s2);
	}
	if (!(s2 = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_memcpy(s2, s1, ft_strlen(s1) + 1));
}
