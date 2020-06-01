/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinrich <heinrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:42:42 by hbarnard          #+#    #+#             */
/*   Updated: 2020/06/01 18:55:20 by heinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			map_count(void)
{
	static int	i = -1;

	i++;
	return (i);
}

int			main(void)
{
	char			*mappy[MAP_MAX];
	t_room			*rooms;
	t_path			*path;

	populate_map(mappy, &rooms);
	room_swap(&rooms);
	set_ants(mappy, &rooms);
	breadth(find_start(&rooms));
	path = construct_path(rooms);
	disp_map(mappy);
	traversal(path, &rooms);
	free_rooms(&rooms);
	free_paths(&path);
}