/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:33:54 by cbester           #+#    #+#             */
/*   Updated: 2018/06/04 09:38:35 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*templist;

	if (!(*alst) || !(del))
		return ;
	while (*alst)
	{
		templist = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = templist;
	}
	*alst = NULL;
}
