/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:41:55 by twebb             #+#    #+#             */
/*   Updated: 2020/01/31 10:41:57 by twebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

int			check_paths(t_room *room)
{
	while (room->type != END)
		room = room->next;
	if (room->dist == 0)
		return (1);
	return (0);
}

void		reverse(t_path **path)
{
	t_path	*prev;
	t-path	*current;
	t_path	*next;

	current = *path;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next_room;
		current->next_room = prev;
		prev = current;
		current = next;
	}
	*path = prev;
}

t_path		*construct_path(t_room *start)
{
	t_room	*end;
	t_links	*tmp_link;
	t_path	*path;

	end = start;
	while (end->type != END)
		end = end->next;
	path = NULL;
	add_path(&path, end->name);
	while (end->dist != 1)
	{
		tmp_link = end->links;
		while (tmp_link)
		{
			if (tmp_link->room->dist == end->dist - 1)
			{
				add_path(&path, tmp_link->room->name);
				end = tmp_link->room;
			}
			tmp_link = tmp_link->next;
		}
	}
	reverse(&path);
	return (path);
}

void		breadth(t_room *start)
{
	t_queue	*queuel;
	t_links	*tmp_link;
	t_room	*room;
	t_room	*end;

	end = start;
	while (end->type != END)
		end = end->next;
	room = start;
	queue = queue_new(room);
	room->dist = 1;
	while (queue && end->dist == 0)
	{
		tmp_link = queue->room->links;
		while (tmp_link)
		{
			if (tmp_link->room->dist == 0)
				QUEUE_ADD;
			tmp_link = tmp_link->next;
		}
		queue_remove(&queue);
	}
	end->dist ? NULL : (NO_PATHS);
	while (queue)
		queue_remove(&queue);
}
