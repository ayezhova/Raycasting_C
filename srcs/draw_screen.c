#include "raycasting.h"

float ft_fabs(float a)
{
    return a < 0 ? a * -1 : a;
}

void get_step_direct(s_dist_calc *dist, s_position *pos)
{
    if (dist->ray_dir[0] < 0)
    {
        dist->step_dir[0] = -1;
        dist->dist_next_x = (pos->cur_position[0] - dist->map_loc[0])
            * dist->change_in_x;
    }
    else
    {
        dist->step_dir[0] = 1;
        dist->dist_next_x = (dist->map_loc[0] + 1 - pos->cur_position[0])
            * dist->change_in_x;
    }
    if (dist->ray_dir[1] < 0)
    {
        dist->step_dir[1] = -1;
        dist->dist_next_y = (pos->cur_position[1] - dist->map_loc[1])
            * dist->change_in_y;
    }
    else
    {
        dist->step_dir[1] = 1;
        dist->dist_next_y = (dist->map_loc[1] + 1 - pos->cur_position[1])
            * dist->change_in_y;
    }
}

void set_dist_vars(s_dist_calc *dist, int col, s_map *map, s_position *pos)
{
    dist->camera_loc = (2.0 * col / map->R_x) - 1.0;
    // printf("-----COL %d camera %f-----\n", col, dist->camera_loc);
    dist->ray_dir[0] = pos->cur_direction[0] + pos->camera_plane[0]
        * dist->camera_loc;
    dist->ray_dir[1] = pos->cur_direction[1] + pos->camera_plane[1]
        * dist->camera_loc;
    dist->map_loc[0] = (int)pos->cur_position[0];
    dist->map_loc[1] = (int)pos->cur_position[1];
    dist->change_in_x = (dist->ray_dir[1] == 0) ? 0 : ((dist->ray_dir[0] == 0)
        ? 1 : ft_fabs(1 / dist->ray_dir[0]));
    dist->change_in_y = (dist->ray_dir[0] == 0) ? 0 : ((dist->ray_dir[1] == 0)
        ? 1 : ft_fabs(1 / dist->ray_dir[1]));
    dist->side_hit = 0;
    get_step_direct(dist, pos);
}

void move_till_wall(s_dist_calc *dist, s_map *map_info)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (dist->dist_next_x < dist->dist_next_y)
        {
            // printf("b");
            dist->dist_next_x += dist->change_in_x;
            dist->map_loc[0] += dist->step_dir[0];
            dist->side_hit = 0;
        }
        else
        {
            // printf("a");
            dist->dist_next_y += dist->change_in_y;
            dist->map_loc[1] += dist->step_dir[1];
            dist->side_hit = 1;
        }
        if (map_info->map_array[dist->map_loc[0]][dist->map_loc[1]] == '1')
            hit = 1;
    }
}

void calc_height_wall(s_dist_calc *dist, s_map *map_info, s_position *pos)
{
    int start;
    int stop;

    // printf("Side: %d\n", dist->side_hit);
    //remove step from calculation
    if (dist->side_hit == 0)
        dist->dist_to_wall = ((float)dist->map_loc[0] - pos->cur_position[0] +
            (1.0 - (float)dist->step_dir[0]) / 2.0) / dist->ray_dir[0];
    else
        dist->dist_to_wall = (dist->map_loc[1] - pos->cur_position[1] +
            (1.0 - dist->step_dir[1]) / 2.0) / dist->ray_dir[1];
    // printf("map x %d, map y %d, cur x %f, cur y %f, step x: %d, step y: %d, ray x %f, ray y%f\n", dist->map_loc[0], dist->map_loc[1], pos->cur_position[0], pos->cur_position[1], dist->step_dir[0], dist->step_dir[1], dist->ray_dir[0], dist->ray_dir[1]);
    // printf("height: %d, dist: %f\n", map_info->R_y, dist->dist_to_wall);
    // printf("expec: %f, width: %d\n", map_info->R_y / dist->dist_to_wall, map_info->R_y);
    //take div by 0 into account
    dist->line_height = (int)(map_info->R_y / dist->dist_to_wall);
    dist->line_height = dist->dist_to_wall == 0 ? map_info->R_y : (int)(map_info->R_y / dist->dist_to_wall);
    // printf("line height: %d\n", dist->line_height);
    start = map_info->R_y / 2 - dist->line_height / 2;
    dist->row_start = start > 0 ? start : 0;
    stop = map_info->R_y / 2 + dist->line_height / 2;
    dist->row_stop = stop < map_info->R_y ? stop : map_info->R_y - 1;
}

void draw_screen(s_map *map_info, s_position *pos, s_mlx_pnts *mlx_pnts)
{
    int col;
    s_dist_calc dist;
    s_line new_line;
    int point1[2];
    int point2[2];


    col = 0;
    //    while (col < 1)
    //while (col < map_info->R_x)
    while (col < map_info->R_x)
    {
        set_dist_vars(&dist, col, map_info, pos);
        move_till_wall(&dist, map_info);
        calc_height_wall(&dist, map_info, pos);
        point1[0] = col;
        point1[1] = dist.row_start;
        point2[0] = col;
        point2[1] = dist.row_stop;
        // printf("(%d, %d), (%d %d)\n", point1[0], point1[1], point2[0], point2[1]);
        new_segment(&new_line, point1, point2);
        if (dist.side_hit == 0)
            drawline(new_line, mlx_pnts, 0x346eeb);
        else
        {
            drawline(new_line, mlx_pnts, 0x475470);
        }
        col++;
    }
}