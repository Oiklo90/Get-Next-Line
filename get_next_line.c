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

char			*ft_strjoin2(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int				ft_copy_to_c(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoin2(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}

static t_list	*ft_get_list(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*gnl;
	char			buf[BUFF_SIZE + 1];
	t_list			*list;
	int				pos;
	size_t			i;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	list = ft_get_list(&gnl, fd);
	VERIF((*line = ft_strnew(1)));
	while ((pos = read(fd, buf, BUFF_SIZE)))
	{
		buf[pos] = '\0';
		VERIF((list->content = ft_strjoin(list->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (pos <= BUFF_SIZE && !ft_strlen(list->content))
		return (0);
	i = ft_copy_to_c(line, list->content, '\n');
	if (i < ft_strlen(list->content))
		list->content += (i + 1);
	else
		ft_strclr(list->content);
	return (1);
}
