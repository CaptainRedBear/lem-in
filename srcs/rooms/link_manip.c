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
