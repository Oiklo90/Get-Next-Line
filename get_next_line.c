/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:14:00 by llonger           #+#    #+#             */
/*   Updated: 2017/11/16 11:14:00 by llonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list		*ft_get_list(t_list **gnl, size_t fd)
{
	t_list			*tmp;

	tmp = *gnl;
	while (tmp)
	{
		if (tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	VERIFNULL((tmp = (t_list *)malloc(sizeof(t_list))));
	tmp->content_size = fd;
	VERIFNULL((tmp->content = ft_strnew(0)));
	tmp->next = NULL;
	ft_lstadd(gnl, tmp);
	tmp = *gnl;
	return (tmp);
}

static char			*get_line(t_list *list, char **line)
{
	int				i;
	char			*file;
	char			*tmp;

	i = 0;
	file = list->content;
	while (file[i])
	{
		if (file[i] == '\n')
		{
			if ((*line = ft_strsub(file, 0, i)) == 0)
				return (NULL);
			tmp = file;
			VERIFNULL((file = ft_strdup(file + (i + 1))));
			free(tmp);
			return (file);
		}
		i++;
	}
	VERIFNULL((*line = ft_strdup(file)));
	ft_strclr(file);
	ft_strclr(list->content);
	return (file);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*gnl = NULL;
	char			buf[BUFF_SIZE + 1];
	t_list			*list;
	int				pos;
	char			*tmp;

	list = gnl;
	if (fd < 0 || !line || (list = ft_get_list(&gnl, fd)) == NULL)
		return (-1);
	while (!ft_strchr(list->content, '\n'))
	{
		if ((pos = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else if (pos == 0)
			break ;
		buf[pos] = 0;
		tmp = list->content;
		VERIF((list->content = ft_strjoin(list->content, buf)));
		free(tmp);
	}
	if ((list->content = get_line(list, line)) == NULL)
		return (-1);
	if (!ft_strlen(list->content) && !ft_strlen(*line) && !pos)
		return (0);
	return (1);
}
