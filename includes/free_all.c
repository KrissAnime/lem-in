/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:35:10 by cbester           #+#    #+#             */
/*   Updated: 2018/09/03 11:19:39 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	free_ant(t_ant **ant)
{
	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	free_array((*ant)->links, ft_array_size((*ant)->links));
}
