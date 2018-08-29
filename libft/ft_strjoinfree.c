/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 10:22:34 by cbester           #+#    #+#             */
/*   Updated: 2018/08/29 10:22:35 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str = ft_strnew((ft_strlen(s1) + ft_strlen((char*)s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy((str + ft_strlen(s1)), (char*)s2);
	free(&(*s1));
	return (str);
}
