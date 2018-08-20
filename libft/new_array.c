/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:56:26 by cbester           #+#    #+#             */
/*   Updated: 2018/08/20 11:59:40 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**new_array(char *first)
{
	char	**new;

	if (!(new = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	new[0] = ft_strdup(first);
	new[1] = NULL;
	return (new);
}

char	**new_array_free(char *first)
{
	char	**new;

	if (!(new = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	new[0] = ft_strdup(first);
	new[1] = NULL;
	free(first);
	return (new);
}
