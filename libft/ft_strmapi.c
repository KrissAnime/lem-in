/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:54:59 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:36:00 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[x] = (*f)(x, s[x]);
		x++;
	}
	str[x] = '\0';
	return (str);
}
