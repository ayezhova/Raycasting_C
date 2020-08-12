#include "raycasting.h"

int get_map(int fd, char *str, s_map *map_info)
{
    char *line;
    char *temp1;
    char *temp2;
    int ret;

    map_info->map = ft_strnew(0);
    map_info->height = 0;
    line = str;
    ret = 1;
    while (ret == 1)
    {
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

int add_line_to_info(char *str, char *untrimmed, s_map *map_info, int fd)
{
    int ret;
    int i;

    ret = 1;
    i = 0;
    while (i < MAP_VAR)
    {
        if (ft_strncmp(str, map_info->expected[i], ft_strlen(map_info->expected[i])) == 0)
            break;
        i++;
    }
    if (i <= MAP_VAR - 1)
        map_info->pnt_array[i] = str;
    else
    {
        free(str);
        ret = get_map(fd, untrimmed, map_info);
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
        if (trimmed_line[0] != '\0')
        {
            //if applies to one of the 8 pointers, add it to the pointer. otherwise break (assume rest of map follows)
            ret = add_line_to_info(trimmed_line, line, map_info, fd);
            if (ret == -1 || ret == 0)
                return ret;
        }
        free(line);
    }
    return 1;
}

void print_info(s_map *map_info)
{
    //debugging
    int i = 0;

    while (i < MAP_VAR)
    {
        if (map_info->pnt_array[i])
            printf("%s %s|||\n", map_info->expected[i], map_info->pnt_array[i]);
        i++;
    }
    if (map_info->map)
        printf("%s\n", map_info->map);
}

void init_data_given(s_map *map_info)
{
    int i;

    i = 0;
    while (i < MAP_VAR)
    {
        map_info->data_given[i] = 0;
        i++;
    }
}

void free_char_map(s_map *map_info)
{
    int i;

    i = 0;
    while (i < MAP_VAR)
    {
        if (map_info->pnt_array[i])
            free(map_info->pnt_array[i]);
        i++;
    }
    i = 0;
    while (map_info->expected[i])
        free(map_info->expected[i++]);
    free(map_info->expected);
    if (map_info->map)
        free(map_info->map);
    i = 0;
    while (i < map_info->height)
    {
        free(map_info->map_array[i++]);
    }
    free(map_info->map_array);
}

int parse_file(char *map_file, s_map *map_info)
{
    int fd;
    int i;
    int ret;

    if (!(fd = open(map_file, O_RDONLY)))
        return 0;
    init_data_given(map_info);
    ret = read_file(fd, map_info);
    print_info(map_info);
    if (ret != -1)
        ret = check_map_valid(map_info);
    if (ret == 0)
        ret = check_inputs(map_info);
    close(fd);
    if (ret == 0)
        map_info->map_int_array = map_int_array(map_info->map_array, map_info->start);
    free_char_map(map_info);
    return ret;
}