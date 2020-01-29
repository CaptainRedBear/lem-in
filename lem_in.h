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

/*
**macros
*/

# define POOR_FORM {ft_putendl("Error : Map input poorly formatted."); exit(1);}
# define MULTI_START {ft_putendl("Error : One start room allowed."); exit(1);}
# define MULTI_END {ft_putendl("Error : One end room allowed."); exit(1);}
# define MALLOC_ERR {ft_putendl("Error : Malloc Error."); exit(1);}
# define DUP_NAME {ft_putendl("Error : Duplicate room names present"); exit(1);}
# define POS_CLASH {ft_putendl("Error : Overlapping room positions"); exit(1);}
# define E2E {n[3]->next = n[2]->next; n[1]->next = n[2]; n[2]->next = NULL;}

/*
**structs
*/

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

typedef struct		s_co_ord
{
	int				x;
	int				y;
}					t_co_ord;

typedef struct		s_room
{
	char			*name;
	t_co_ord		pos;
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
	int				scount;
	char			end;
	int				ecount;
}					t_se;

typedef struct		s_ant
{
	int				ant_num;
	char			*curr_room;
	t_path			*path;
}					t_ant;

/*
**validation
*/

void				val_map(void);
void				val_room(void);

/*
**struct control
*/

t_room				*add_room(t_room **room, char **data, int type);
t_room				*new_room(char **data, int type);
t_room				*find_start(t_room **rooms);
void				free_rooms(t_room **room);
void				free_links(t_links **link);
void				room_swap(t_room **rooms);

/*
**misc
*/

t_room				*find_room(t_room *room, char *name);

#endif
