/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:59:36 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/29 13:59:37 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

void	free_paths(t_path **path)
{
	t_path *next;

	if (!*path)
		return ;
	while (*path)
	{
		next = (*path)->next_room;
		free((*path)->room_name);
		free(*path);
		*path = next;
	}
	*path = NULL;
}

t_path	*new_path(char *room_name)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		MALLOC_ERR;
	new->room_name = ft_strdup(room_name);
	new->next_room = NULL;
	return (new);
}

t_path	*add_path(t_path **path, char *room_name)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = new_path(room_name);
		return (*path);
	}
	while (tmp->next_room)
		tmp = tmp->next_room;
	tmp->next_room = new_path(room_name);
	return (*path);
}

size_t	path_length(t_path *path)
{
	size_t	count;

	count = 0;
	while (path)
	{
		count++;
		path = path->next_room;
	}
	return (count);
}
