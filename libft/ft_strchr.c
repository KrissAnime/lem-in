/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:10:22 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:34:47 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	t_byte	x;
	size_t	i;

	i = 0;
	x = (t_byte)c;
	while (i <= ft_strlen(s))
	{
		if (x == s[i])
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
