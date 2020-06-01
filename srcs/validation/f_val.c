/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_val.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinrich <heinrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:58:41 by ldu-pree          #+#    #+#             */
/*   Updated: 2020/05/31 16:23:13 by heinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

void	set_ants(char **mappy, t_room **rooms)
{
	int		i;
	t_room	*tmp;

	tmp = *rooms;
	i = 0;
	while (tmp && tmp->type != 1)
		tmp = tmp->next;
	while (!ft_isdigit(mappy[i][0]))
		i++;
	tmp->ant_count = ft_atoi(mappy[i]);
}

void	val_ants(char *s, char **mappy, t_room **room)
{
	char	*ants;
	char	*file;

	file = NULL;
	if (ft_strncmp("#", s, 1) == 0)
	{
		if (ft_strcmp("#start", s + 1) == 0 || ft_strcmp("#end", s + 1) == 0)
			NO_ANTS;
		mappy[map_count()] = ft_strdup(s);
		get_next_line(0, &file);
		validate(file, mappy, 0, room);
		free(file);
	}
	else
	{
		ants = ft_itoa(ft_atoi(s));
		if (ft_strcmp(ants, s) != 0)
			NO_ANTS;
		if (ft_atoi(s) < 0)
			BAD_ANTS;
		mappy[map_count()] = ft_strdup(s);
		ft_strdel(&ants);
	}
}

t_room	*val_room(char *s, char **mappy, int type, t_room **room)
{
	char	**info;
	char	*pos[2];

	info = ft_strsplit(s, ' ');
	pos[0] = ft_itoa(ft_atoi(info[1]));
	if (ft_strcmp(pos[0], info[1]) != 0)
		BAD_X;
	pos[1] = ft_itoa(ft_atoi(info[2]));
	if (ft_strcmp(pos[1], info[2]) != 0)
		BAD_Y;
	mappy[map_count()] = ft_strdup(s);
	ft_strdel(&pos[0]);
	ft_strdel(&pos[1]);
	add_room(room, info, type);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	free(info);
	return (*room);
}

void	link_check(char **link, t_room **room)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = *room;
	ft_strequ(link[0], link[1]) ? (MISLINK) : NULL;
	while (tmp->next)
	{
		i = ft_strequ(link[0], tmp->name) ? i + 1 : i;
		i = ft_strequ(link[1], tmp->name) ? i + 1 : i;
		tmp = tmp->next;
	}
	i = ft_strequ(link[0], tmp->name) ? i + 1 : i;
	i = ft_strequ(link[1], tmp->name) ? i + 1 : i;
	i != 2 ? (MISLINK) : NULL;
}

void	val_link(char *s, char **mappy, t_room **room)
{
	char		**pair;
	int			n;

	n = 0;
	pair = ft_strsplit(s, '-');
	while (pair[n] != NULL)
		n++;
	if (n != 2)
		POOR_FORM;
	link_check(pair, room);
	add_link(room, pair[0], pair[1]);
	add_link(room, pair[1], pair[0]);
	mappy[map_count()] = ft_strdup(s);
	free(pair[0]);
	free(pair[1]);
	free(pair);
}