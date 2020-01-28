
#include "../lem_in.h"

static int		check_lines(char *str, char sp)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == sp)
			count++;
		i++;
	}
	return (count);
}
void val_room(){
    
}
void val_map(){
    char *line;
    int start;
    int end;

    start = 0;
    end = 0;
    while (get_next_line(0, &line)){
        //printf("%s\n", line);
        if (ft_strcmp(line, "##start") == 0) {
            start++;
            get_next_line(0, &line);
             //printf("%s\n", line);
            if (ft_strncmp(line, "##", 2) != 0)
                check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
            if (ft_strcmp(line, "##start") == 0)
                start++;
        } else if (ft_strcmp(line, "##end") == 0){
            end++;
            get_next_line(0, &line);
            if (ft_strncmp(line, "##", 2) != 0)
                check_lines(line, ' ') == 2 ? val_room() : (POOR_FORM);
            if (ft_strcmp(line, "##end") == 0)
                end++;
        }
    }
    if (end > 1)
        MULTI_END;
    if (start > 1)
        MULTI_START;
}
