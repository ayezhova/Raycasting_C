#include "raycasting.h"

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
            dist->dist_next_x += dist->change_in_x;
            dist->map_loc[0] += dist->step_dir[0];

            dist->side_hit = 0;
        }
        else
        {
            dist->dist_next_y += dist->change_in_y;
            dist->map_loc[1] += dist->step_dir[1];
            dist->side_hit = 1;
        }
        if (map_info->map_int_array[dist->map_loc[0]][dist->map_loc[1]] == 1)
            hit = 1;
    }
}

void calc_height_wall(s_dist_calc *dist, s_map *map_info, s_position *pos)
{
    int start;
    int stop;

    if (dist->side_hit == 0)
    {
        dist->dist_to_wall = ((float)dist->map_loc[0] - pos->cur_position[0] +
            (1.0 - (float)dist->step_dir[0]) / 2.0) / dist->ray_dir[0];
        dist->exact_hit = pos->cur_position[1] +
            dist->dist_to_wall * dist->ray_dir[1];
    }
    else
    {
        dist->dist_to_wall = (dist->map_loc[1] - pos->cur_position[1] +
            (1.0 - dist->step_dir[1]) / 2.0) / dist->ray_dir[1];
        dist->exact_hit = pos->cur_position[0] +
            dist->dist_to_wall * dist->ray_dir[0];
    }
    dist->line_height = (int)(map_info->R_y / dist->dist_to_wall);
    dist->line_height = (dist->dist_to_wall == 0) ? map_info->R_y * MIN_TO_WALL
        : (int)(map_info->R_y / dist->dist_to_wall);
    start = map_info->R_y / 2 - dist->line_height / 2;
    dist->row_start = start > 0 ? start : 0;
    stop = map_info->R_y / 2 + dist->line_height / 2;
    dist->row_stop = stop < map_info->R_y ? stop : map_info->R_y;
}

void draw_screen(s_map *map_info, s_position *pos, s_mlx_pnts *mlx_pnts, s_img *new_img)
{
    int col;
    s_dist_calc dist;
    s_img orig_img;
    s_background back_info;

    printf("x: %f, y: %f\n", pos->cur_position[0], pos->cur_position[1]);
    init_back_info(&back_info, map_info);
    orig_img.img_pnt = mlx_xpm_file_to_image(mlx_pnts->mlx_pnt,
        "default_textures/wall_1.xpm", &orig_img.width, &orig_img.height);
    orig_img.mem_address = mlx_get_data_addr(orig_img.img_pnt,
        &orig_img.bits_per_pixel, &orig_img.size_line, &orig_img.endian);
    col = 0;
    new_img->bits_per_pixel = new_img->size_line / new_img->width;
    orig_img.bits_per_pixel = orig_img.size_line / orig_img.width;
    clear_img(new_img);
    mlx_clear_window(mlx_pnts->mlx_pnt, mlx_pnts->win_pnt);
    while (col < map_info->R_x)
    {
        set_dist_vars(&dist, col, map_info, pos);
        move_till_wall(&dist, map_info);
        calc_height_wall(&dist, map_info, pos);
        
        add_col_to_image(&back_info, &dist, new_img, &orig_img);
        col++;
    }
    mlx_put_image_to_window(mlx_pnts->mlx_pnt, mlx_pnts->win_pnt, new_img->img_pnt, 0, 0);
}