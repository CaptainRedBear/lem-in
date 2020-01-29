/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:59:55 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/29 13:59:56 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

t_queue			*queue_new(t_room *room)
{
	t_queue	*new;

	if (!room)
		return (NULL);
	new = (t_queue *)malloc(sizeof(t_list));
	new->room = room;
	new->next = NULL;
	return (new);
}

void			queue_add(t_queue *queue, t_room *room)
{
	if (!queue)
	{
		queue = queue_new(room);
		return ;
	}
	while (queue->next)
	{
		if (queue->room == room)
			return ;
		queue = queue->next;
	}
	queue->next = queue_new(room);
}

void			queue_remove(t_queue **queue)
{
	t_queue *tmp;

	if (!queue)
		return ;
	tmp = (*queue)->next;
	free(*queue);
	*queue = tmp;
}
