/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_big_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:33:59 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 10:38:23 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_big_array(char ***array)
{
	int	x;

	x = 0;
	while (x)
	{
		free_array(array[x], ft_array_size(array[x]));
		x++;
	}
	free(array);
}
