/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:37:28 by hbarnard          #+#    #+#             */
/*   Updated: 2019/07/25 14:01:24 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ccpy(char **line, char *content, char c)
{
	int		i;

	i = 0;
	while (content[i] && content[i] != c)
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	return (i);
}

t_list	*curr_lst(const int fd, t_list **readlist)
{
	t_list	*curr;

	if (!readlist)
		return (NULL);
	curr = *readlist;
	while (curr)
	{
		if (curr->content_size == (size_t)fd)
			return (curr);
		curr = curr->next;
	}
	curr = ft_lstnew("", fd);
	ft_lstadd(readlist, curr);
	return (curr);
}

int		read_loop(const int fd, char **content)
{
	int		res;
	char	*removal;
	char	buf[BUFF_SIZE + 1];

	while ((res = read(fd, buf, BUFF_SIZE)))
	{
		buf[res] = '\0';
		removal = *content;
		if (!(*content = ft_strjoin(*content, buf)))
			return (-1);
		free(removal);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (res);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*readlist;
	int				suc;
	char			*temp;
	t_list			*curr;

	if (fd < 0 || !line || read(fd, buf, 0) < 0
	|| (!(curr = curr_lst(fd, &readlist))))
		return (-1);
	temp = curr->content;
	suc = read_loop(fd, &temp);
	curr->content = temp;
	if (!suc && !*temp)
		return (0);
	suc = ccpy(line, curr->content, '\n');
	temp = curr->content;
	if (temp[suc] != '\0')
	{
		curr->content = ft_strdup(&(curr->content[suc + 1]));
		free(temp);
	}
	else
		temp[0] = '\0';
	return (1);
}
