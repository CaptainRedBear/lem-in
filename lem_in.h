/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:32:52 by hbarnard          #+#    #+#             */
/*   Updated: 2020/01/28 10:32:53 by hbarnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include "./libft/libft.h"

# define POOR_FORM {ft_putendl("Error : Map input poorly formatted."); exit(1);}
# define MULTI_START {ft_putendl("Error : One start room allowed."); exit(1);}
# define MULTI_END {ft_putendl("Error : One end room allowed."); exit(1);}
# define VALID_START {ft_putendl("Start : Valid."); exit(1);}
# define VALID_END {ft_putendl("End : Valid."); exit(1);}

void			val_map(void);

typedef struct		s_path
{
	char			*room_name;
	struct s_path	*next_room;
}					t_path;

typedef struct		s_links
{
	char			*link;
	struct s_room	*room;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	//t_co_ord		pos;
	t_links			*links;
	int				type;
	int				ant_count;
	int				x_path;
	int				dist;
	int				rcount;
	struct s_room	*next;
}					t_room;

typedef	struct		s_se{
	char			start;
	char			end;
}					t_se;

typedef struct		s_ant
{
	int				ant_num;
	char			*curr_room;
	t_path			*path;
}					t_ant;

#endif