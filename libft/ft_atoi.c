/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:46:11 by cbester           #+#    #+#             */
/*   Updated: 2018/06/01 11:35:28 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(const char *str)
{
	int		c;

	c = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n' || str[c] == '\r'
			|| str[c] == '\f' || str[c] == '\v')
		c++;
	return (c);
}

static void	ft_isneg(int *neg, char *c)
{
	if (*c == '-')
	{
		*neg = -1;
	}
	else if (*c == '+')
	{
		*neg = 1;
	}
}

int			ft_atoi(const char *str)
{
	int		i;
	long	r;
	int		neg;

	i = ft_whitespace(str);
	r = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_isneg(&neg, (char*)&str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (neg == -1 && r < 0)
		return (0);
	else if (neg == 1 && r < 0)
		return (-1);
	return (neg * (int)r);
}
