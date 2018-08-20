/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:30:39 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:34:07 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	index;
	size_t	index2;

	index = ft_strlen(s1);
	index2 = 0;
	while (index2 < ft_strlen(s2))
	{
		s1[index] = s2[index2];
		index2++;
		index++;
	}
	s1[index] = '\0';
	return (s1);
}
