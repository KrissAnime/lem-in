/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:15:50 by cbester           #+#    #+#             */
/*   Updated: 2018/06/18 10:12:36 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(ptr, size + 1);
	return (ptr);
}
