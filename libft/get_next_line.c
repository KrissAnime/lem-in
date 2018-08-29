/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 09:52:53 by cbester           #+#    #+#             */
/*   Updated: 2018/08/29 10:22:47 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*line_ret(char *str, t_list *file)
{
	size_t	x;
	size_t	len;
	char	*ret;
	char	*temp;

	x = 0;
	len = ft_strlen(str);
	while (str[x] && str[x] != '\n')
		x++;
	ret = ft_strsub(str, 0, x);
	if (!str[x] || (str[x] && !str[x + 1]))
	{
		ft_strdel(&str);
		file->content = str;
		return (ret);
	}
	temp = str;
	str = ft_strdup(str + x + 1);
	free(temp);
	file->content = str;
	return (ret);
}

static t_list	*find_file(const int fd, t_list **list)
{
	t_list	*file;

	file = *list;
	while (file)
	{
		if ((int)file->content_size == fd)
			return (file);
		file = file->next;
	}
	file = ft_lstnew(0, fd);
	file->content = ft_strnew(0);
	file->content_size = fd;
	ft_lstadd(list, file);
	return (file);
}

size_t			read_file(const int fd, char **str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	while (!(ft_strchr(*str, '\n')))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (ERROR);
		buff[ret] = '\0';
		*str = ft_strjoinfree(*str, buff);
		if (ret == 0)
		{
			if (**str == '\0')
			{
				free(*str);
				*str = NULL;
				return (DONE);
			}
			break ;
		}
	}
	return (READ);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files;
	t_list			*file;
	char			*str;
	size_t			ret;

	if (BUFF_SIZE <= 0 || !line || fd < -1)
		return (ERROR);
	file = find_file(fd, &files);
	str = file->content;
	if (!str)
		str = ft_strnew(0);
	ret = read_file(fd, &str);
	if (ret != 1)
		return (ret);
	*line = line_ret(str, file);
	return (READ);
}
