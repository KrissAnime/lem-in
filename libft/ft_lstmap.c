/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 06:51:51 by cbester           #+#    #+#             */
/*   Updated: 2018/06/04 13:11:35 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*templist;
	t_list	*startlist;

	if (!(lst) || !(*f))
		return (NULL);
	if (!(templist = f(lst)))
	{
		free(templist);
		return (NULL);
	}
	startlist = templist;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(templist->next = f(lst)))
		{
			free(templist->next);
			return (NULL);
		}
		templist = templist->next;
	}
	templist->next = NULL;
	return (startlist);
}
