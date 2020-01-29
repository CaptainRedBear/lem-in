/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:32:21 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/29 12:32:23 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

t_room	*find_room(t_room *room, char *name)
{
	while (room)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (room);
}
