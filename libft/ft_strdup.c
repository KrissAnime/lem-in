/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:14 by cbester           #+#    #+#             */
/*   Updated: 2018/05/24 09:07:23 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(s2, s1));
}
