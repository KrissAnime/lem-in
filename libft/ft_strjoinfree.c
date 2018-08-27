/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:04:48 by swilson           #+#    #+#             */
/*   Updated: 2018/08/24 09:04:50 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char *str_new;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str_new = ft_strnew((size_t)(ft_strlen((char *)s1)
					+ ft_strlen((char *)s2) + 1))))
		return (NULL);
	ft_strcpy(str_new, (char *)s1);
	ft_strcpy((str_new + ft_strlen((char *)s1)), (char *)s2);
	free(&(*s1));
	return (str_new);
}
