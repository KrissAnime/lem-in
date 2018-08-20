/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 07:11:32 by cbester           #+#    #+#             */
/*   Updated: 2018/07/14 08:57:40 by cbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoinfree(char *s1, char *s2)
{
	size_t	x;
	size_t	ls1;
	size_t	ls2;
	char	*str;

	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	if (!(s1) || !(s2))
		return (NULL);
	if (!(str = (char*)malloc(ls1 + ls2 + 1)))
		return (NULL);
	x = -1;
	while (s1[++x] != '\0')
		str[x] = s1[x];
	x = -1;
	while ((s2[++x]) != '\0')
		str[x + ls1] = s2[x];
	free(s1);
	str[x + ls1] = '\0';
	return (str);
}

static void		ft_copy_buff(t_list **control, char **line)
{
	int		i;
	int		x;
	char	*temp;

	i = 0;
	temp = ((char*)(*control)->content);
	x = ft_strlen(temp);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	(*line) = ft_strsub((*control)->content, 0, i);
	if (x > i)
	{
		temp = (*control)->content;
		temp = ft_strsub(temp, i + 1, x);
		free((*control)->content);
		(*control)->content = ft_strdup(temp);
		free(temp);
	}
	else
		ft_strclr((*control)->content);
}

static t_list	*ft_valid_buff(int fd, t_list **files)
{
	t_list	*temp;

	temp = *files;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(files, temp);
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*files = NULL;
	t_list			*control;
	char			buff[BUFF_SIZE + 1];
	int				r;

	if (fd < 0 || !line || (r = read(fd, buff, 0) < 0))
		return (-1);
	control = ft_valid_buff(fd, &files);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		control->content = ft_strjoinfree(control->content, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if ((ft_strlen((control)->content)) == 0 && r < 1)
		return (0);
	ft_copy_buff(&control, line);
	return (1);
}
