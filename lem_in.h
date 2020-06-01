/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinrich <heinrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:32:52 by hbarnard          #+#    #+#             */
/*   Updated: 2020/06/01 19:51:09 by heinrich         ###   ########.fr       */
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
# define NO_START {ft_putendl("Error : Start room required."); exit(1);}
# define NO_END {ft_putendl("Error : End room required."); exit(1);}
# define NO_PATHS {ft_putendl("Error : No path to end."); exit(1);}
# define NO_ANTS {ft_putendl("Error : No value for ants."); exit(1);}
# define BAD_ANTS {ft_putendl("Error: Ants must be an integer > 0."); exit(1);}
# define BAD_X {ft_putendl("Error : Invalid value for x-coordinate."); exit(1);}
# define BAD_Y {ft_putendl("Error : Invalid value for y-coordinate."); exit(1);}
# define MALLOC_ERR {ft_putendl("Error : Failed to malloc."); exit(1);}
# define DUP_NAME {ft_putendl("Error: Duplicate room names."); exit(1);}
# define POS_CLASH {ft_putendl("Error : Overlapping rooms."); exit(1);}
# define DUP_LINK {ft_putendl("Error: Duplicate links."); exit(1);}
# define MISLINK {ft_putendl("Error: Invalid room link."); exit(1);}

# define PATHS_MAX 255
# define MAP_MAX 100000
# define START 1
# define END 2
# define E2E {n[3]->next = n[2]->next; n[1]->next = n[2]; n[2]->next = NULL;}

# define Q_1 {queue_add(queue, tmp_link->room);
# define Q_2 tmp_link->room->dist = queue->room->dist + 1;}
# define QUEUE_ADD Q_1 Q_2

typedef struct		s_path
{
	char			*room_name;
	struct s_path	*next_room;
}					t_path;

typedef struct		s_co_ord
{
	int				x;
	int				y;
}					t_co_ord;

typedef struct		s_links
{
	char			*link;
	struct s_room	*room;
	struct s_links	*next;
}					t_links;

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

typedef struct		s_staend
{
	int				start;
	int				end;
}					t_staend;

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
** Validation
*/
void				validate(char *s, char **mappy, int mode, t_room **room);
void				val_ants(char *s, char **mappy, t_room **room);
t_room				*val_room(char *s, char **mappy, int type, t_room **room);
void				val_link(char *s, char **mappy, t_room **room);
int					populate_map(char **mappy, t_room **room);
void				link_check(char **link, t_room **room);
int					contains_dup(t_path *start);
void				set_ants(char **mappy, t_room **rooms);
void				disp_map(char **map);

/*
** List handling
*/
t_room				*new_room(char **info, int type);
t_room				*add_room(t_room **room, char **info, int type);
void				free_rooms(t_room **room);
t_links				*new_link(t_room *room, char *name);
void				add_link(t_room **room, char *name1, char *name2);
void				free_links(t_links **link);
t_path				*new_path(char *room_name);
t_path				*add_path(t_path **path, char *room_name);
void				free_paths(t_path **path);
t_queue				*queue_new(t_room *room);
void				queue_add(t_queue *queue, t_room *room);
void				queue_remove(t_queue **queue);

/*
** Room Navigation
*/
t_room				*find_room(t_room *room, char *name);
void				room_swap(t_room **rooms);
void				breadth(t_room *start);
t_path				*construct_path(t_room *start);

/*
** Timothy
*/

void				traversal(t_path *path, t_room **rooms);
void				display_ants(t_ant *ant, t_room **rooms);

/*
** Misc
*/
int					map_count(void);
size_t				array_length(t_path **path);
t_room				*find_start(t_room **rooms);
int					check_paths(t_room *room);

#endif
