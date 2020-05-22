#include "raycasting.h"

int is_edge(int i, int j, s_map *map_info)
{
    if (i == 0 || i == map_info->height - 1 || j == 0 ||
        j == ft_strlen(map_info->map_array[i]) - 1  ||
        j >= ft_strlen(map_info->map_array[i - 1]) - 1 ||
        j >= ft_strlen(map_info->map_array[i + 1]) - 1 ||
        map_info->map_array[i - 1][j] == ' ')
    {
        return 1;
    }
    return 0;
}

int is_orientation(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return 1;
    return 0;
}

int is_invalid(char c)
{
    if (c != ' ' && c != '\n' && c != '0' && c != '1' && c != '2' &&
        !is_orientation(c))
        return 1;
    return 0;
}

int check_orientarion(int i, int j, s_map *map_info)
{
    if (is_edge(i, j, map_info))
        return -3;
    map_info->orientation = map_info->map[i];
    map_info->map_array[i][j] = '0';
    if (map_info->start[0] != -1)
        return -5;
    map_info->start[0] = i;
    map_info->start[1] = j;
    return 1;
}

int check_map_valid(s_map *map_info)
{
    int i;
    int j;

    i = -1;
    map_info->map_array = ft_strsplit(map_info->map, '\n');
    map_info->start[0] = -1;
    while (++i < map_info->height)
    {
        j = -1;
        while (++j < ft_strlen(map_info->map_array[i]))
        {
            if (is_invalid(map_info->map_array[i][j]))
                return -4;
            if (map_info->map_array[i][j] == '0' && is_edge(i, j, map_info))
                return -2;
            if (is_orientation(map_info->map_array[i][j]))
            {
                if (check_orientarion(i, j, map_info) != 1)
                    return -3;
            }
        }
    }
    if (map_info->start[0] == -1)
        return -3;
    return 0;
}

