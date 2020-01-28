
#include "../lem_in.h"

void val_map(){
    char *line;
    int start;
    int end;

    start = 0;
    end = 0;
    while (get_next_line(0, &line)){
        if (ft_strcmp(line, "##start") == 0) {
            start++;
        } else if (ft_strcmp(line, "##end") == 0)
            end++;
    }
    if (end > 1)
        MULTI_END;
    if (start > 1)
        MULTI_START;
}