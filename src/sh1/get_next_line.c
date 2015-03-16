/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 15:31:23 by bfrimin           #+#    #+#             */
/*   Updated: 2015/02/26 17:17:58 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_read	*addlistitem(t_read *list, int fd)
{
	t_read				*tmp;

	if (!(tmp = (t_read *)malloc(sizeof(*list))))
		return (NULL);
	if (tmp)
	{
		tmp->fd = fd;
		if (!(tmp->content = ft_strdup("")))
			return (NULL);
		if (list)
			list->next = tmp;
		tmp->next = NULL;
	}
	return (tmp);
}

static int		reading(int fd, char **len, t_read **node)
{
	char	*buf;
	int		ret;
	char	*tmp;

	if (!(buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (-1);
	while (!(*len = ft_strchr((*node)->content, '\n'))
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if ((*node)->content != 0)
		{
			tmp = (*node)->content;
			if (!((*node)->content = ft_strjoin(tmp, buf)))
				return (-1);
			free(tmp);
		}
		else
			(*node)->content = ft_strdup(buf);
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_read	*first;
	t_read			*node;
	char			*len;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	first = (first ? first : addlistitem(first, fd));
	if (!first)
		return (-1);
	node = first;
	while (node->fd != fd && node->next != NULL)
		node = node->next;
	node = (node->fd == fd ? node : addlistitem(node, fd));
	if (!node || reading(fd, &len, &node) == -1)
		return (-1);
	if (len || ((len = ft_strchr(node->content, '\0')) && node->content[0]))
	{
		if (!(*line = ft_strsub(node->content, 0, len - node->content)))
			return (-1);
		if (!(node->content = ft_strdup(len + 1)))
			return (-1);
		return (1);
	}
	return (0);
}
