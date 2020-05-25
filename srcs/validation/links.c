
#include "../../lem_in.h"

void    print_links(t_room **room);
void			val_links()
{
	// char	*lines1;
	// int		count;
    // int     fd;
	// //int		se;

	// //se = 0;
	// count = 0;
	// while (get_next_line(fd, &lines1))
	// {
	// 	if (count >= 0)
	// 	{
	// 		if (check_lines(lines1, '#') == 0 && check_lines(lines1, '-') == 1)
	// 		{
	// 			new_valid_link(room,lines1);
	// 		}
    //         printf("Count\n");
	// 	}
	// 	count++;
	// }
    // printf("Count\n");
    // print_links(room);
}


void        new_valid_link(t_room **room, char *line)
{
    char *room1;
    char *room2;
    int i = 0,j;

    while(line[i] != '\0' && line[i] != '-')
    {
        i++;
    }
    j = i;
    room1 = ft_memalloc(i + 1);
    while(line[j] != '\0')
    {
        j++;
    }
    room2 = ft_memalloc(j - i);
    i = 0;
    while(line[i] != '\0' && line[i] != '-')
    {
        room1[i] = line[i];
        i++;
    }
    room1[i] = '\0';
    i++;
    j = 0;
    while(line[i] != '\0')
    {
        room2[j] = line[i];
        i++;
        j++;
    }
    room2[j] = '\0';
    //printf("Add links name1[%s] name2[%s]\n", room1, room2);
    add_link(room, room1, room2);
}

void        print_links(t_room **room)
{
    t_room *tmp = NULL;
	t_links *tmplink = NULL;
	tmp = *room;
	while (tmp)
	{
		tmplink = tmp->links;
		while(tmplink)
		{
			printf("%s-%s\n", tmp->name, tmplink->link);
			tmplink = tmplink->next;
		}
		tmp = tmp->next;
	}
}