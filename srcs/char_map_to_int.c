#include "raycasting.h"

int get_space_between_letters(char **map_array)
{
    int i;
    int j;
    int space_bet_letters;
    int len;

    i = -1;
    space_bet_letters = 0;
    while (map_array[++i])
    {
        space_bet_letters = 0;
        j = -1;
        while (++j < ft_strlen(map_array[i]))
        {
            while (map_array[i][j] == ' ')
                j++;
            j++;
            space_bet_letters = j;
            while (j < ft_strlen(map_array[i]) && map_array[i][j] == ' ')
                j++;
            if (map_array[i][j] && map_array[i][j] != ' ')
                return j - space_bet_letters;
        }
    }
    return space_bet_letters;
}

int len_array(char **map_array)
{
    int i;

    i = 0;
    while (map_array[i])
    {
        i++;
    }
    return i;
}

int *get_map_row(char *map_str, int space_bet_letters)
{
    int len_row_str;
    int len_row;
    int *map_row;
    int i;
    int j;

    len_row_str = ft_strlen(map_str);
    if (len_row_str % 2 == 0)
        len_row = len_row_str / (space_bet_letters + 1);
    else
        len_row = (len_row_str / (space_bet_letters + 1)) + 1;
    map_row = (int *)malloc(sizeof(int) * len_row);
    i = 0;
    j = 0;
    while (i < len_row)
    {
        if (map_str[j] == ' ')
            map_row[i] = 0;
        else if (map_str[j] == '0' || map_str[j] == '1' || map_str[j] == '2')
            map_row[i] = map_str[j] - '0';
        i++;
        j += space_bet_letters + 1;
    }
    return map_row;
}

int **map_int_array(char **map_array)
{
    int **map_int_array;
    int i;
    int j;
    int space_bet_letters;
    int len;

    i = 0;
    j = 0;
    space_bet_letters = get_space_between_letters(map_array);
    len = len_array(map_array);
    map_int_array = (int **)malloc(sizeof(int *) * len);
    while (i < len)
    {
        map_int_array[i] = get_map_row(map_array[i], space_bet_letters);
        i++;
    }
    return map_int_array;
}