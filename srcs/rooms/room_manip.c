/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:21:21 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/28 13:21:24 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

t_room	*new_room(char **data, int type)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		MALLOC_ERR;
	new->name = ft_strdup(data[0]);
	new->pos.x = ft_atoi(data[1]);
	new->pos.y = ft_atoi(data[2]);
	new->type = type;
	new->ant_count = 0;
	new->x_path = 0;
	new->dist = 0;
	new->links = NULL;
	new->next = NULL;
	return (new);
}

t_room	*add_room(t_room **room, char **data, int type)
{
	t_room *tmp;

	tmp = *room;
	if (!*room)
	{
		*room = new_room(data, type);
		return(*room);
	}
	while (tmp)
	{
		ft_strequ(data[0], tmp->name) ? (DUP_NAME) : NULL;
		if (tmp->pos.x == ft_atoi(data[1]))
			tmp->pos.y == ft_atoi(data[2]) ? (POS_CLASH) : NULL;
		if (tmp->next){
			tmp = tmp->next;
		} else {
			tmp->next = new_room(data, type);
			break;
		}
		//printf("Room name[%s] x[%d] y[%d]\n", tmp->name, tmp->pos.x, tmp->pos.y);
	}
	(*room)->rcount++;
	return (*room);
}

void	free_rooms(t_room **room)
{
	t_room *next;

	while (*room)
	{
		free_links(&((*room)->links));
		free((*room)->name);
		free(*room);
		next = (*room)->next;
		(*room) = next;
	}
	*room = NULL;
}

t_room	*find_start(t_room **rooms)
{
	t_room *tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 1)
		tmp = tmp->next;
	return (tmp);
}

void	room_swap(t_room **rooms)
{
	t_room	*n[4];

	n[0] = *rooms;
	n[1] = *rooms;
	n[2] = *rooms;
	while (n[0] && n[0]->type != 1)
		n[0] = n[0]->next;
	while (n[2] && n[2]->type != 2)
		n[2] = n[2]->next;
	if (!ft_strequ(n[1]->name, n[0]->name))
	{
		while (!ft_strequ(n[1]->next->name, n[0]->name))
			n[1] = n[1]->next;
		n[1]->next = n[0]->next;
		n[0]->next = *rooms;
		*rooms = n[0];
	}
	n[1] = *rooms;
	n[3] = *rooms;
	while (n[1] && n[1]->next)
		n[1] = n[1]->next;
	while (n[3] && n[3]->next->type != 2)
		n[3] = n[3]->next;
	if (!ft_strequ(n[1]->name, n[2]->name))
		E2E;
}
