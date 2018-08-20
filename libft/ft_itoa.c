/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:10:55 by cbester           #+#    #+#             */
/*   Updated: 2018/08/10 10:19:44 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_numsize(int n)
{
	int	x;
	int	i;

	i = n;
	x = 1;
	while (i >= 10)
	{
		i = i / 10;
		x++;
	}
	return (x);
}

static char	*ft_minint(void)
{
	char	*str2;
	int		i;
	char	*str;

	i = 1;
	str2 = "-2147483648";
	if (!(str = malloc(sizeof((char*)(12)))))
		return (NULL);
	str[0] = '-';
	while (i < 12)
	{
		str[i] = str2[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_numconv(char *str, int n, int i, int s)
{
	str[--i] = '\0';
	if (ft_numsize(n) == 1)
		str[--i] = n + '0';
	while (n)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	if (--s)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		s;
	char	*str;

	s = 1;
	if (n == -2147483648)
		return (ft_minint());
	if (n < 0)
	{
		s = 2;
		n = n * -1;
	}
	if (!(str = (char*)malloc(ft_numsize(n) + s)))
		return (NULL);
	i = ft_numsize(n) + s;
	return (ft_numconv(str, n, i, s));
}
