/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:49:45 by ldu-pree          #+#    #+#             */
/*   Updated: 2020/01/31 12:49:47 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static	int		checkx(int i, int *x, int k, char *line)
{
	char	*coord;
	int		l;

	coord = NULL;
	l = 0;
	while (line[i] != ' ')
	{
		i++;
		l++;
	}
	coord = ft_memalloc(l);
	l = 0;
	i = k + 1;
	while (line[i] != ' ')
	{
		ft_isdigit(line[i]) ? NULL : (BAD_X);
		coord[l] = line[i];
		i++;
		l++;
	}
	coord[l] = '\0';
	*x = atoi(coord);
	k = i;
	return (k);
}

static	int		checky(int i, int *y, int k, char *line)
{
	char	*coord;
	int		l;

	coord = NULL;
	l = 0;
	while (line[i])
	{
		i++;
		l++;
	}
	coord = NULL;
	coord = ft_memalloc(l);
	l = 0;
	i = k + 1;
	while (line[i])
	{
		ft_isdigit(line[i]) ? NULL : (BAD_Y);
		coord[l] = line[i];
		i++;
		l++;
	}
	coord[l] = '\0';
	*y = atoi(coord);
	k = i;
	return (k);
}

void			ch_room(char *line, t_room **room)
{
	char	*name;
	int		i;
	int		j;
	int		k;
	int		count;
	int		x;
	int		y;
	char 	*data[4];

	O7;
	while (line[i])
	{
		if (line[i] == ' ' && count == 0)
			CH_ROOM_NAME;
		if (line[i] == ' ' && count == 1)
			CH_ROOM_X;
		if (line[i + 1] == '\0' && count == 2)
		{
			CH_ROOM_Y;
		}
		i++;
	}
	data[0] = ft_memalloc(strlen(name)+1);
	data[1] = ft_memalloc(100);
	data[2] = ft_memalloc(100);
	data[0] = name;
	data[1] = ft_itoa(x);
	data[2] = ft_itoa(y);
	if (room)
		i = 0;
	if (ft_strcmp(data[0],"start") == 0){
		add_room(room, data, 1);
	} else {
		add_room(room, data, 2);
	}
	printf("name[%s] x[%d] y[%d]\n", name, x, y);
}

void			val_rooms(t_room **room)
{
	char	*lines;
	int		count;
	//int		se;

	//se = 0;
	count = 0;
	while (get_next_line(0, &lines))
	{
		if (count >= 0)
		{
			if (ft_strncmp(lines, "##", 2) == 0)
			{
				//se = count;
				val_se(lines);
			}
			if (check_lines(lines, ' ') != 2 && check_lines(lines, '-') != 1 &&
			ft_strncmp(lines, "#", 1) != 0)
				POOR_FORM;
			if (ft_strncmp(lines, "#", 1) != 0 && check_lines(lines, ' ') == 2)
			{
				ch_room(lines, room);
			}
		}
		count++;
	}
	MULTI_CHECK;
	NO_CHECK;
}
