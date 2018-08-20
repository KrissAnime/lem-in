/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:10:02 by cbester           #+#    #+#             */
/*   Updated: 2018/05/28 14:18:39 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;
	size_t	x;

	i = 0;
	x = 0;
	c = 0;
	while (s1[i] != '\0' && i < n)
	{
		x += (t_byte)s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		c += (t_byte)s2[i];
		i++;
	}
	return (x - c);
}
