/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:19:32 by cbester           #+#    #+#             */
/*   Updated: 2018/05/23 08:24:07 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_byte	x;
	int		i;

	i = ft_strlen(s);
	x = (t_byte)c;
	while (i >= 0)
	{
		if (x == s[i])
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}
