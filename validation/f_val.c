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
		*(str + i) == sp ? (count++) : exit(1);
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

	start = 0;
	end = 0;
	while (get_next_line(0, &line))
	{
		ft_putstr("WHY GOD WHY\n");
		if (ft_strcmp(line, "##start") == 0)
		{
			start++;
			get_next_line(0, &line);
			if (ft_strncmp(line, "##", 2) != 0)
				check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
			ft_strcmp(line, "##start") == 0 ? (start++) : (int)NULL;
		}
		else if (ft_strcmp(line, "##end") == 0)
		{
			end++;
			get_next_line(0, &line);
			if (ft_strncmp(line, "##", 2) != 0)
				check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
			ft_strcmp(line, "##end") == 0 ? (end++) : (int)NULL;
		}
	}
	end > 1 ? (MULTI_END) : NULL;
	start > 1 ? (MULTI_START) : NULL;
}
