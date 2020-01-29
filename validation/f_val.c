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

#include "../lem_in.h"

static int		check_lines(char *str, char sp)
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

void			val_room(void)
{
	int i;

	i = 0;
	i++;
}

void			val_map(void)
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
				check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
			ft_strcmp(line, "##start") == 0 ? (start++) : 0;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			END;
			if (ft_strncmp(line, "##", 2) != 0)
				check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
			ft_strcmp(line, "##end") == 0 ? (end++) : 0;
		}
	}
	end > 1 ? (MULTI_END) : NULL;
	start > 1 ? (MULTI_START) : NULL;
}
