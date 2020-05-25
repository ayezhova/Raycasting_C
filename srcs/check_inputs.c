#include "raycasting.h"

int check_r(s_map *map_info)
{
    //check that in the form R # #
    //Remember that R must be greater than 0
    int i;
    char *str;
    int num;
    int val;

    i = 2;
    num = 0;
    str = *map_info->R;
    while (i < ft_strlen(str))
    {
        val = ft_atoi(&str[i]);
        if (val < 100 || val > 2000)
            return -5;
        if (num == 0)
            map_info->R_x = val;
        else if (num == 1)
            map_info->R_y = val;
        if (!(str[i] >= '0' && str[i] <= '9'))
            return -5;
        while (str[i] && str[i] >= '0' && str[i] <= '9')
            i++;
        num++;
        if (str[i] == ' ')
            i++;
    }
    if (num != 2)
        return -5;
    return 0;
}

int check_path(s_map *map_info, int i)
{
    int fd;
    int size;

    size = ft_strlen(map_info->expected[i]);
    if (!(fd = open(&map_info->pnt_array[i][size], O_RDONLY)))
        return -1;
    if (fd == -1)
        return -1;
    close(fd);
    return 0;
}

void init_color(char *str)
{
    int i;

    i = 0;
    while (i < 8)
    {
        str[i] = '0';
        i++;
    }
    str[i] = '\0';
}

int add_to_hex(char *hex, char *color_str, int num)
{
    int len;
    char *val_str;
    int val;
    int pos;

    pos = num * 2;
    val = ft_atoi(color_str);
    if (val < 0 || val > 255 || num > 2)
        return 0;
    val_str = ft_itoa_base(val, 16, 1, &len);
    if (len == 1)
    {
        hex[pos] = '0';
        hex[pos + 1] = val_str[0];
    }
    else
    {
        hex[pos] = val_str[0];
        hex[pos + 1] = val_str[1];
    }
    free(val_str);
    return 1;
}

int hex_str_to_int(char *hex)
{
    int num;
    int i;

    i = 0;
    num = 0;
    while (i < 6)
    {
        num *= 16;
        if (hex[i] >= '0' && hex[i] <= '9')
            num += hex[i] - '0';
        else
            num += hex[i] - 'a' + 10;
        i++;
    }
    return num;
}

int check_colors(s_map *map_info, int color)
{
    //i is 6 or 7, 
    int i;
    int num;
    char *str;
    char hex[7];
    int val;

    hex[6] = '\0';
    i = 2;
    num = 0;
    str = map_info->pnt_array[color];
    while (i < ft_strlen(str))
    {   
        if (!(str[i] >= '0' && str[i] <= '9'))
            return -5;
        if (!add_to_hex(hex, &str[i], num))
            return -5;
        while (str[i] && str[i] >= '0' && str[i] <= '9')
            i++;
        num++;
        if (str[i] == ',')
            i++;
    }
    map_info->colors[color - 6] = hex_str_to_int(hex);
    //set hexstr to int, and that int to raycasting variable
    return (num != 3) ? -5 : 0;
}

int check_inputs(s_map *map_info)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    while (i < MAP_VAR && ret == 0)
    {
        if (map_info->pnt_array[i])
        {
            if (i == 0)
                ret = check_r(map_info);
            else if (i >= 1 && i <= 5)
                ret = check_path(map_info, i);
            else
                ret = check_colors(map_info, i);
        }
        i++;
    }
    return ret;
}