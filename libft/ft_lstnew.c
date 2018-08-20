/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:38:57 by cbester           #+#    #+#             */
/*   Updated: 2018/06/08 12:25:06 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*templist;

	if (!(templist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		templist->content = NULL;
		templist->content_size = 0;
	}
	else
	{
		if (!(templist->content = malloc(content_size)))
		{
			free(templist);
			return (NULL);
		}
		ft_memcpy(templist->content, content, content_size);
		templist->content_size = content_size;
	}
	templist->next = NULL;
	return (templist);
}
