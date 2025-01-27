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
# define NO_MAP {ft_putendl("Error : No map input"); exit(1);}
# define MULTI_START {ft_putendl("Error : One start room allowed."); exit(1);}
# define MULTI_END {ft_putendl("Error : One end room allowed."); exit(1);}
# define MALLOC_ERR {ft_putendl("Error : Malloc Error."); exit(1);}
# define DUP_NAME {ft_putendl("Error : Duplicate room names present"); exit(1);}
# define DUP_LINK {ft_putendl("Error : Duplicate links present"); exit(1);}
# define POS_CLASH {ft_putendl("Error : Overlapping room positions"); exit(1);}
# define E2E {n[3]->next = n[2]->next; n[1]->next = n[2]; n[2]->next = NULL;}
# define START {startcount++;}
# define END {endcount++;}
# define DECLARE {start = 0; end = 0;}
# define O1 {endcount > 1 ? (MULTI_END) : NULL;}
# define O2 {startcount > 1 ? (MULTI_START) : NULL;}
# define O3 {end == 1 ? add_room()  : NULL;}
# define O4 {start == 1 ? add_room() : NULL;}
# define O5 {endcount == 0 ? (NO_END) : NULL;}
# define O6 {startcount == 0 ? (NO_START) : NULL;}
# define O7 {i = 0; j = 0; k = 0; x = 0; y = 0; count = 0;}
# define O8 {k = i; j = i; i = 0; name = ft_memalloc(j); O10;}
# define O9 {name[j+1] = '\0'; i = j+1; count++;}
# define O10 {name = ft_strndup(line, j);}
# define O11 {count++; i = j+1;}
# define O12 {k = checky(i, &y, k, line); count++;}
# define CH_ROOM_NAME {O8;O9;}
# define CH_ROOM_X {j = i; i = k + 1; k = checkx(i, &x, k, line); O11;}
# define CH_ROOM_Y {j = ft_strlen(line); i = k + 1; O12;}
# define MULTI_CHECK {O1; O2;}
# define NO_CHECK {O5; O6;}
# define NO_START {ft_putendl("Error : Start room required."); exit(1);}
# define NO_END {ft_putendl("Error : End room required."); exit(1);}
# define NO_PATHS {ft_putendl("Error : No path to end."); exit(1);}
# define BAD_ANTS {ft_putendl("Error: Ants must be an integer > 0."); exit(1);}
# define BAD_X {ft_putendl("Error : Invalid value for x-coordinate."); exit(1);}
# define BAD_Y {ft_putendl("Error : Invalid value for y-coordinate."); exit(1);}

# define Q_1 {queue_add(queue, tmp_link->room);
# define Q_2 tmp_link->room->dist = queue->room->dist + 1;}
# define QUEUE_ADD Q_1 Q_2
# define END1 {2;}

extern int endcount;
extern int startcount;

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
	struct s_co_ord	pos;
	struct s_links	*links;
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

typedef struct		s_queue
{
	t_room			*room;
	struct s_queue	*next;
}					t_queue;

/*
**validation
*/

void				val_map(t_room **room);
void				val_se(char *line);
void				val_ants(void);
void				val_rooms(t_room **room);
void        		new_valid_link(t_room **room, char *line);
void				val_links();
void    			print_links(t_room **room);
void				ch_room(char *line, t_room **room);
int					check_lines(char *str, char sp);

/*
**struct control
*/

t_room				*add_room(t_room **room, char **data, int type);
t_room				*new_room(char **data, int type);
t_room				*find_start(t_room **rooms);
void				free_rooms(t_room **room);
void				free_links(t_links **link);
void				room_swap(t_room **rooms);
t_links				*new_link(t_room *room, char *name);
void				add_link(t_room **room, char *name1, char *name2);
t_queue				*queue_new(t_room *room);
void				queue_add(t_queue *queue, t_room *room);
void				queue_remove(t_queue **queue);
void				free_paths(t_path **path);
t_path				*new_path(char *room_name);
t_path				*add_path(t_path **path, char *room_name);
size_t				path_length(t_path *path);

/*
**Made by Tim
*/

void				display_ants(t_ant *ant, t_room **rooms);
void				traversal(t_path *path, t_room **rooms);
void				disp_map(char **map);
t_room				*find_room(t_room *room, char *name);
void				breadth(t_room *start);

#endif
