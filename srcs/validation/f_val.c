/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_val.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:58:41 by ldu-pree          #+#    #+#             */
/*   Updated: 2020/01/28 13:58:44 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

int endcount;
int startcount;

int				check_lines(char *str, char sp)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (sp)
		i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sp)
			count++;
		i++;
	}
	return (count);
}

void			val_se(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		startcount++;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		endcount++;
	}
}

void			val_ants(void)
{
	char	*lines;
	int		ants;
	int		i;

	i = 0;
	get_next_line(0, &lines);
	while (lines[i])
	{
		ft_isdigit(lines[i]) ? NULL : (BAD_ANTS);
		i++;
	}
	ants = atoi(lines);
	ants > 0 ? NULL : (BAD_ANTS);
}

void			val_map(t_room **room)
{
	val_ants();
	val_rooms(room);
}
