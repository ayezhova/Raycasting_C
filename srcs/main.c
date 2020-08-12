#include "raycasting.h"

int key_hook(int keycode, s_key_arg *key_args)
{
    if (keycode == UP_ARROW)
        move_up(key_args->map_info->map_int_array, key_args->pos);
    else if (keycode == DOWN_ARROW)
        move_down(key_args->map_info->map_int_array, key_args->pos);
    else if (keycode == RIGHT_ARROW)
        rotate_right(key_args->map_info->map_int_array, key_args->pos);
    else if (keycode == LEFT_ARROW)
        rotate_left(key_args->map_info->map_int_array, key_args->pos);
    else if (keycode == ESC)
        escape_cub3d(key_args->map_info);
    draw_screen(key_args->map_info, key_args->pos, key_args->mlx_pnts, key_args->new_img);
    return keycode;
}

void set_up_pnts(s_mlx_pnts *pnts, s_map *map_info)
{
    pnts->mlx_pnt = mlx_init();
    pnts->win_pnt = mlx_new_window(pnts->mlx_pnt, map_info->R_x, map_info->R_y, "Title");
}

void init_map_info(s_map *map_info)
{
    int i;

    map_info->R = &map_info->pnt_array[0];
    map_info->NO = &map_info->pnt_array[1];
    map_info->SO = &map_info->pnt_array[2];
    map_info->WE = &map_info->pnt_array[3];
    map_info->EA = &map_info->pnt_array[4];
    map_info->S = &map_info->pnt_array[5];
    map_info->F = &map_info->pnt_array[6];
    map_info->C = &map_info->pnt_array[7];
    map_info->orientation = ' ';
    map_info->expected = ft_strsplit("R .NO .SO .WE .EA .S .F .C ", '.');
    i = 0;
    while (i < MAP_VAR)
        map_info->pnt_array[i++] = NULL;
    map_info->map = NULL;
    map_info->colors[0] = 0xFFFFFF;
    map_info->colors[1] = 0xFFFFFF;
    map_info->R_x = 500;
    map_info->R_y = 500;
}

void free_map_info(s_map *map_info)
{
    int i;

    i = 0;
    while (i < map_info->height)
    {
        free(map_info->map_int_array[i++]);
    }
    free(map_info->map_int_array);
}

void escape_cub3d(s_map *map_info)
{
    printf("Thanks for playing!\n");
    free_map_info(map_info);
    exit(0);
}

void set_key_args(s_key_arg *key_args, s_map *map_info, s_position *pos_info,
    s_mlx_pnts *mlx_pnts)
{
    key_args->map_info = map_info;
    key_args->pos = pos_info;
    key_args->mlx_pnts = mlx_pnts;
    key_args->map_array = map_info->map_array;
}

void error_quit(int error_code, s_map *map_info)
{
    if (error_code == -1)
        ft_putstr("Error reading file\n");
    else if (error_code == -2)
        ft_putstr("Outside of map must be 1's\n");
    else if (error_code == -3)
        ft_putstr("Player rotation must be present once within inside of map\n");
    else if (error_code == -4)
        ft_putstr("Invalid characters in map\n");
    else if (error_code == -5)
        ft_putstr("Invalid form\n");
    free_map_info(map_info);
}

void start_game(s_map *map_info)
{
    s_mlx_pnts mlx_pnts;
    s_position pos_info;
    s_key_arg key_args;
    s_img new_img;

    set_up_pos_info(&pos_info, map_info);
    set_up_pnts(&mlx_pnts, map_info);
    mlx_key_hook(mlx_pnts.win_pnt, key_hook, &key_args);
    set_key_args(&key_args, map_info, &pos_info, &mlx_pnts);
    key_args.new_img = &new_img;
    new_img.img_pnt = mlx_new_image(mlx_pnts.mlx_pnt, map_info->R_x, map_info->R_y);
    new_img.mem_address = mlx_get_data_addr(new_img.img_pnt,
        &new_img.bits_per_pixel, &new_img.size_line, &new_img.endian);
    new_img.width = map_info->R_x;
    new_img.height = map_info->R_y;
    draw_screen(map_info, &pos_info, &mlx_pnts, &new_img);
    mlx_loop(mlx_pnts.mlx_pnt);
}

int main(int argc, char **argv)
{
    s_map map_info;
    int ret;

    init_map_info(&map_info);
    if (argc == 3)
    {
        if (ft_strcmp(argv[1], "-m") == 0)
        {
            ret = parse_file(argv[2], &map_info);
            if (ret == 0)
            {
                start_game(&map_info);    
            }
            else
                error_quit(ret, &map_info);
        }
    }
}