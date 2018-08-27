/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 08:51:10 by swilson           #+#    #+#             */
/*   Updated: 2018/07/20 09:12:52 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 50
# define FD content_size
# define STRING content

int					get_next_line(const int fd, char **line);

typedef struct		s_gnl
{
	char			*string;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;
#endif