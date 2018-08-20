/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:38:32 by cbester           #+#    #+#             */
/*   Updated: 2018/08/20 12:41:57 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prints to the any output the elements of array seperated by character c
*/

void	print_array(char **array, char c, int fd)
{
	size_t	x;

	x = 0;
	while (array[x])
	{
		ft_putstr_fd(array[x], fd);
		ft_putchar(c);
		x++;
	}
}
