#include "raycasting.h"

void set_north_direction(s_position *pos_info)
{
    pos_info->cur_direction[0] = -1.0;
    pos_info->cur_direction[1] = 0.0;
    pos_info->camera_plane[0] = 0;
    pos_info->camera_plane[1] = 0.66;
}

void set_east_direction(s_position *pos_info)
{
    pos_info->cur_direction[0] = 0.0;
    pos_info->cur_direction[1] = 1.0;
    pos_info->camera_plane[0] = 0.66;
    pos_info->camera_plane[1] = 0;
}

void set_south_direction(s_position *pos_info)
{
    pos_info->cur_direction[0] = 1.0;
    pos_info->cur_direction[1] = 0.0;
    pos_info->camera_plane[0] = 0.0;
    pos_info->camera_plane[1] = -0.66;
}

void set_west_direction(s_position *pos_info)
{
    pos_info->cur_direction[0] = 0.0;
    pos_info->cur_direction[1] = -1.0;
    pos_info->camera_plane[0] = -0.66;
    pos_info->camera_plane[1] = 0;
}

void set_up_pos_info(s_position *pos_info, s_map *map_info)
{
    pos_info->cur_position[0] = (float)map_info->start[0] + 0.25;
    pos_info->cur_position[1] = (float)map_info->start[1] + 0.25;
    if (map_info->orientation == 'N')
        set_north_direction(pos_info);
    if (map_info->orientation == 'E')
        set_east_direction(pos_info);
    if (map_info->orientation == 'S')
        set_south_direction(pos_info);
    if (map_info->orientation == 'W')
        set_west_direction(pos_info);
}
