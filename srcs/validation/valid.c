/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinrich <heinrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:42:42 by hbarnard          #+#    #+#             */
/*   Updated: 2020/05/31 20:53:46 by heinrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static int		char_jam(char *s, char brk)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == brk)
			n++;
		i++;
	}
	return (n);
}

static void		val_cmd(char *s, char **mappy, t_staend *se, t_room **room)
{
	char	*next;

	if (ft_strcmp(s, "##start") == 0)
	{
		if (se->start == 1)
			MULTI_START;
		get_next_line(0, &next);
		char_jam(next, ' ') == 2 ? val_room(next, mappy, 1, room) : (POOR_FORM);
		se->start = 1;
		free(next);
	}
	if (ft_strequ(s, "##end"))
	{
		if (se->end == 1)
			MULTI_END;
		get_next_line(0, &next);
		char_jam(next, ' ') == 2 ? val_room(next, mappy, 2, room) : (POOR_FORM);
		se->end = 1;
		free(next);
	}
}

static void		val_m1(char *s, int *roomy, char **mappy, t_room **room)
{
	if (char_jam(s, ' ') == 2 && *roomy == 0)
		val_room(s, mappy, 0, room);
	else if (char_jam(s, ' ') == 0 && char_jam(s, '-'))
	{
		if (*roomy == 0)
			validate(NULL, NULL, 0, room);
		*roomy = 1;
		val_link(s, mappy, room);
	}
	else
		POOR_FORM;
}

void			validate(char *s, char **mappy, int mode, t_room **room)
{
	static t_staend		se;
	static int			roomy;

	if (s == NULL)
	{
		if (!se.start)
			NO_START;
		if (!se.end)
			NO_END;
	}
	else if (mode == 0)
		val_ants(s, mappy, room);
	else if (ft_strncmp("#", s, 1) == 0)
	{
		mappy[map_count()] = ft_strdup(s);
		if (ft_strncmp("#", s + 1, 1) == 0)
			val_cmd(s, mappy, &se, room);
	}
	else if (ft_strncmp("L", s, 1) == 0)
	{
		POOR_FORM;
	}
	else if (mode == 1)
		val_m1(s, &roomy, mappy, room);
}

int				populate_map(char **mappy, t_room **room)
{
	char	*file;

	get_next_line(0, &file);
	validate(file, mappy, 0, room);
	free(file);
	while (get_next_line(0, &file))
	{
		validate(file, mappy, 1, room);
		(file) ? free(file) : NULL;
	}
	free(file);
	validate(NULL, NULL, 42, room);
	return (1);
}