/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:23:53 by cbester           #+#    #+#             */
/*   Updated: 2018/05/24 14:10:28 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	x;
	size_t	z;
	size_t	y;
	char	*str;

	if (!(s))
		return (NULL);
	x = 0;
	z = ft_strlen(s) - 1;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	while ((s[z] == ' ' || s[z] == '\n' || s[z] == '\t') && z > x)
		z--;
	if (!(str = malloc((char)(z - x + 2))))
		return (NULL);
	y = 0;
	z += 1;
	while (x < z)
	{
		str[y] = (char)s[x];
		y++;
		x++;
	}
	str[y] = '\0';
	return (str);
}
