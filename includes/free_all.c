/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <cbester@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:35:10 by cbester           #+#    #+#             */
/*   Updated: 2018/09/17 09:25:02 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/lem_in.h"

void	free_ant(t_ant **ant)
{
	free_array((*ant)->rooms, ft_array_size((*ant)->rooms));
	free_array((*ant)->links, ft_array_size((*ant)->links));
}

void	error(void)
{
	ft_putendl("Error");
	exit(1);
}

void	error_msg(char *msg)
{
	ft_putendl(msg);
	exit(1);
}
