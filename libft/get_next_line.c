/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:35:25 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/25 12:51:48 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcattoc(char *dst, char const *src, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && src[j] != c)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

int		logic(char **buff, char **line)
{
	if (ft_strchr((char const*)*buff, '\n'))
	{
		*line = ft_strcattoc(*line, (char const*)*buff, '\n');
		*buff = ft_strcpy(*buff, (ft_strchr((char const*)*buff, '\n') + 1));
		return (1);
	}
	*line = ft_strcat(*line, (char const*)*buff);
	*buff[0] = '\0';
	return (0);
}

char	*fetch_correct_fd(t_list **head, int fd)
{
	t_list	*temp;

	if (!*head)
	{
		*head = ft_lstnew("", fd);
		free((*head)->content);
		(*head)->content = ft_strnew(BUFF_SIZE + 1);
		(*head)->next = NULL;
	}
	temp = *head;
	while (temp->next)
	{
		if ((temp->content_size) == (size_t)fd)
			return ((char*)(temp->content));
		temp = temp->next;
	}
	if (temp->content_size != (size_t)fd)
	{
		temp->next = ft_lstnew("", fd);
		temp = temp->next;
		free(temp->content);
		temp->content = ft_strnew(BUFF_SIZE + 1);
		temp->next = NULL;
	}
	return ((char*)(temp->content));
}

void	freenode(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*temp2;

	temp = *head;
	if ((temp->content_size) == (size_t)fd)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (((temp->next)->content_size) != (size_t)fd)
		temp = temp->next;
	temp2 = temp;
	temp = temp->next;
	temp2->next = temp->next;
	free(temp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*buff;
	int				ret;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	buff = fetch_correct_fd(&head, fd);
	*line = ft_strnew(250000);
	while (buff[0] != '\0')
		if (logic(&buff, &*line) == 1)
			return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (logic(&buff, &*line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (*line[0] == '\0'))
	{
		freenode(&head, fd);
		return (0);
	}
	return (1);
}
