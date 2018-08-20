/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:25:00 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:35:39 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	x;

	if (!(s))
		return (NULL);
	if (!(str = malloc((char)(ft_strlen(s) + 1))))
		return (NULL);
	x = 0;
	while (x < ft_strlen(s))
	{
		str[x] = (*f)(s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
