/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:33:57 by cbester           #+#    #+#             */
/*   Updated: 2018/08/30 10:39:38 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char **array, size_t x)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < x)
		free(array[i++]);
	free(array);
}
