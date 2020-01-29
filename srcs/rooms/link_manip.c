/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:19:05 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/28 14:19:06 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

void	free_links(t_links **link)
{
	t_links *next;

	next = *link;
	while (*link)
	{
		next = (*link)->next;
		free((*link)->link);
		free(*link);
		(*link) = next;
	}
	*link = NULL;
}

t_links	*new_link(t_room *room, char *name)
{
	t_links *new;

	if (!(new = (t_links *)malloc(sizeof(t_links))))
		MALLOC_ERR;
	new->link = ft_strdup(name);
	new->room = find_room(room, new->link);
	new->next = NULL;
	return (new);
}

void	add_link(t_room **room, char *name1, char *name2)
{
	t_room	*tmp;
	t_links	*tmp_link;

	tmp = *room;
	while (tmp && !ft_strequ(name1, tmp->name))
		tmp = tmp->next;
	if (tmp)
	{
		if (!(tmp->links))
		{
			tmp->links = new_link((*room), name2);
			return ;
		}
		tmp_link = tmp->links;
		while (tmp_link->next)
		{
			ft_strequ(tmp_link->link, name2) ? (DUP_LINK) : NULL;
			tmp_link = tmp_link->next;
		}
		if (ft_strequ(tmp_link->link, name2))
			DUP_LINK;
		tmp_link->next = new_link((*room), name2);
	}
}