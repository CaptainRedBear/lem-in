/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:59:22 by twebb             #+#    #+#             */
/*   Updated: 2020/01/29 12:59:33 by twebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

void				disp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		free(map[i]);
		i++;
	}
	ft_putstr("\n");
}

static void			insfn(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->ant_num);
	ft_putchar('-');
	ant->path = ant->path->next_room;
	ant->curr_room = ant->path->room_name;
}

void				disp_ants(t_ant *ant, t_room **rooms)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 2)
		tmp = tmp->next;
	if (!ft_strequ(ant->curr_room, tmp->name))
	{
		tmp = *rooms;
		while (!ft_strequ(tmp->name, ant->path->next_room->room_name))
			tmp = tmp->next;
		if (tmp->ant_count == 0 || tmp->type == 2)
		{
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count -= 1;
			insfn(ant);
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count += 1;
			ft_putstr(ant->curr_room);
			ft_putchar(' ');
		}
	}
}
