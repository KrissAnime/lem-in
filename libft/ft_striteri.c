/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:41:36 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:33:42 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	x;

	if (!(s) || !(f))
		return ;
	x = 0;
	while (x < ft_strlen(s))
	{
		f(x, &s[x]);
		x++;
	}
}
