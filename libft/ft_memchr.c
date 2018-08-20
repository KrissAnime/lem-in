/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:52:53 by cbester           #+#    #+#             */
/*   Updated: 2018/05/25 11:26:13 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	x;
	t_byte	*tmps;
	size_t	i;

	i = 0;
	x = (t_byte)c;
	tmps = (t_byte*)s;
	while (i < n)
	{
		if (tmps[i] == x)
			return ((void*)&s[i]);
		i++;
	}
	return (NULL);
}
