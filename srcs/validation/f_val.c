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

int		check_lines(char *str, char sp)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) == sp ? (count++) : 0;
		i++;
	}
	return (count);
}

void			val_se(void)
{
	char	*line;
	int		start;
	int		end;

	DECLARE;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "##start") == 0)
		{
			START;
			if (ft_strncmp(line, "##", 2) != 0)
				check_lines(line, ' ') != 2 ? (POOR_FORM) : NULL;
			ft_strcmp(line, "##start") == 0 ? (start++) : 0;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			END;
			if (ft_strncmp(line, "##", 2) != 0)
				check_lines(line, ' ') != 2 ? (POOR_FORM) : NULL;
			ft_strcmp(line, "##end") == 0 ? (end++) : 0;
		}
	}
	MULTI_CHECK;
	NO_CHECK;
	ADDSE;
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

void			val_map(void)
{
	val_rooms();
	// val_ants();
	// val_se();
}
