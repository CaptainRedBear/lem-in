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
		mall_error();
	new->name = ft_strdup(data[0]);
	new->pos.x = ft_strdup(data[1]);
	new->pos.y = ft_strdup(data[2]);
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
		return (*room);
	}
	while (tmp->next)
	{
		ft_strequ(info[0], tmp->name) ? (dup_name()) : NULL;
		if (tmp->pos.x == ft_atoi(data[1]))
			tmp->pos.y == ft_atoi(data[2]) ? (pos_clash()) : NULL;
		tmp = tmp->next;
	}
	ft_strequ(info[0], tmp->name) ? (dup_name()) : NULL;
	if (tmp->pos.x == ft_atoi(data[1]))
		tmp->pos.y == ft_atoi(data[2]) ? (pos_clash()) : NULL;
	tmp->next = new_room(data, type);
	(*room)->rcount++;
	return (*room);
}

t_room	*find_start(t_room **rooms)
{
	t_room *tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 1)
		tmp = tmp->next;
	return (tmp);
}
