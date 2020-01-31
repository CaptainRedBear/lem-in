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

static	int		checkx(int i, int j, int l, int k, char *line, int fcoord, char *coord, char *name)
{
	while (line[i] != ' ')
		i++;
	coord = ft_memalloc(i-j);
	i = k+1;
	while (line[i] != ' ')
	{
		ft_isdigit(line[i]) ? NULL : (BAD_X);
		coord[l] = line[i];
		i++;
		l++;
	}
	coord[l] = '\0';
	fcoord = atoi(coord);
	printf("line=[%s] name=[%s] x=[%d]\n", line, name, fcoord);
	k = i;
	return(i);
}

void			ch_room(char *line)
{
	char	*name;
	int		i;
	int		j;
	int		k;
	int 	l;
	int		count;
	char	*coord;
	int		fcoord;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ' && count == 0)
		{
			k = i;
			j = i;
			i = 0;
			name = ft_memalloc(j);
			name = ft_strndup(line, j);
			name[j+1] = '\0';
			printf("%s[j=[%d]]\n", name, j);
			i = j+1;
			count++;
		}
		if (line[i] == ' ' && count == 1)
		{
			j = i;
			i = k+1;
			checkx(i, j, l, k, line, fcoord, coord, name);
			// while (line[i] != ' ')
			// 	i++;
			// coord = ft_memalloc(i-j);
			// i = k+1;
			// while (line[i] != ' ')
			// {
			// 	ft_isdigit(line[i]) ? NULL : (BAD_X);
			// 	coord[l] = line[i];
			// 	i++;
			// 	l++;
			// }
			// coord[l] = '\0';
			// fcoord = atoi(coord);
			// printf("line=[%s] name=[%s] x=[%d] count{%d}\n", line, name, fcoord, count);
			// k = i;
			count++;
			i = j+1;
		}
		if (line[i+1] == '\0' && count == 2)
		{
			l = 0;
			j = ft_strlen(line);
			i = k+1;
			while (line[i])
				i++;
			coord = NULL;
			coord = ft_memalloc(i-j);
			i = k+1;
			while (line[i])
			{
				ft_isdigit(line[i]) ? NULL : (BAD_X);
				coord[l] = line[i];
				i++;
				l++;
			}
			coord[l] = '\0';
			fcoord = atoi(coord);
			printf("line=[%s] name=[%s] y=[%d] count{%d}\n", line, name, fcoord, count);
			k = i;
			count++;
		}
		i++;
	}
}

void			val_rooms(void)
{
	char	*lines;
	int		count;
	int		se;

	se = 0;
	count = 0;
	while (get_next_line(0, &lines))
	{
		if (count > 1)
		{
			if (ft_strncmp(lines, "##", 2) == 0)
				se = count;
			if (check_lines(lines, ' ') != 2 && check_lines(lines, '-') != 1 &&
			ft_strncmp(lines, "#", 1) != 0)
				POOR_FORM;
			if (ft_strncmp(lines, "#", 1) != 0)
			{
				ch_room(lines);
			}
		}
		count++;
	}
}
