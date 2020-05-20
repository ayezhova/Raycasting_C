#include "raycasting.h"

int get_map(char *map_file, s_map *map_info)
{
    char *line;
    int fd;
    char *temp1;
    char *temp2;
    int ret;
    
    if (!(fd = open(map_file, O_RDONLY)))
        return 0;
    map_info->map = ft_strnew(0);
    map_info->height = 0;
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        if (map_info->height == 0)
            map_info->width = ft_strlen(line);
        temp1 = ft_strjoin(map_info->map, line);
        free(line);
        temp2 = ft_strjoin(temp1, "\n");
        free(map_info->map);
        map_info->map = temp2;
        free(temp1);
        map_info->height = map_info->height + 1;
    }
    close(fd);
    return 1;
}

int check_map_valid(s_map *map_info)
{
    printf("%d %d\n", map_info->height, map_info->width);
    //will need to update height width to start where 1's and 0's start
    //check that only chars are 0, 1, 2 and a single char -> N S E W
    //if more than one pos, invalid
    //must be surrounded by 1's
    return 1;
}