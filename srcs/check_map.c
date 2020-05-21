#include "raycasting.h"

int get_map_2(char *map_file, s_map *map_info)
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

int get_map(int fd, char *str, s_map *map_info)
{
    char *line;
    char *temp1;
    char *temp2;
    int ret;

    map_info->map = ft_strnew(0);
    map_info->height = 0;
    map_info->width = 0;
    line = str;
    ret = 1;
    while (ret == 1)
    {
        if (ft_strlen(line) > map_info->width)
            map_info->width = ft_strlen(line);
        temp1 = ft_strjoin(map_info->map, line);
        free(line);
        temp2 = ft_strjoin(temp1, "\n");
        free(map_info->map);
        map_info->map = temp2;
        free(temp1);
        map_info->height = map_info->height + 1;
        ret = get_next_line(fd, &line);
    }
    return ret;
}

int add_line_to_info(char *str, s_map *map_info, int fd)
{
    int ret;

    ret = 1;
    if (ft_strncmp(str, "R ", 2) == 0)
        map_info->R = str;
    else if (ft_strncmp(str, "NO ", 3) == 0)
        map_info->NO = str;
    else if (ft_strncmp(str, "SO ", 3) == 0)
        map_info->SO = str;
    else if (ft_strncmp(str, "WE ", 3) == 0)
        map_info->WE = str;
    else if (ft_strncmp(str, "EA ", 3) == 0)
        map_info->EA = str;
    else if (ft_strncmp(str, "S ", 2) == 0)
        map_info->S = str;
    else if (ft_strncmp(str, "F ", 2) == 0)
        map_info->F = str;
    else if (ft_strncmp(str, "C ", 2) == 0)
        map_info->C = str;
    else
    {
        printf("Here\n");
        ret = get_map(fd, str, map_info);
    }
    return ret;
}

int read_file(int fd, s_map *map_info)
{
    char *line;
    char *trimmed_line;
    int ret;
    int finished;

    finished = 0;
    ret = 1;
    while (ret == 1)
    {
        ret = get_next_line(fd, &line);
        if (ret == -1 || ret == 0)
            return ret;
        trimmed_line = ft_strtrim(line);
        free(line);
        if (trimmed_line[0] != '\0')
        {
            //if applies to one of the 8 pointers, add it to the pointer. otherwise break (assume rest of map follows)
            ret = add_line_to_info(trimmed_line, map_info, fd);
            if (ret == -1 || ret == 0)
                return ret;
        }
    }
    return 1;
}

void print_info(s_map *map_info)
{
    //debugging
    printf("R\n");
    if (map_info->R)
        printf("%s\n", map_info->R);
    printf("NO\n");
    if (map_info->NO)
        printf("%s\n", map_info->NO);
    printf("SO\n");
    if (map_info->SO)
        printf("%s\n", map_info->SO);
    printf("WE\n");
    if (map_info->WE)
        printf("%s\n", map_info->WE);
    printf("EA\n");
    if (map_info->EA)
        printf("%s\n", map_info->EA);
    printf("S\n");
    if (map_info->S)
        printf("%s\n", map_info->S);
    printf("F\n");
    if (map_info->F)
        printf("%s\n", map_info->F);
    printf("C\n");
    if (map_info->C)
        printf("%s\n", map_info->C);
    printf("Map\n");
    if (map_info->map)
        printf("%s\n", map_info->map);
}

int parse_file(char *map_file, s_map *map_info)
{
    int fd;
    int i;
    int ret;

    if (!(fd = open(map_file, O_RDONLY)))
        return 0;
    ret = read_file(fd, map_info);
    print_info(map_info);
    close(fd);    
    return ret;
}