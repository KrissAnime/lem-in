/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 07:58:48 by cbester           #+#    #+#             */
/*   Updated: 2018/08/31 10:02:15 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array2(char **array, size_t x)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < x)
	{
//		printf("link: %s\taddr before: %p\n", array[i], array[i]);
		ft_strdel(&array[i]);
//		printf("link: %s\taddr after: %p\n", array[i], array[i]);
		i++;
	}
	free(*array);
	free(array);
//	printf("DONE\n");
}
