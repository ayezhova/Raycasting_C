#include "raycasting.h"

int abs(int a)
{
    return a < 0 ? a * -1 : a;
}

void drawline(s_line new_line, void *mlx_pnt, void *win_pnt, int color)
{
    int x;
    int y;
    int p;

    x = new_line.point1[0];
    y = new_line.point1[1];
    p = 2 * new_line.dy - new_line.dx;
    while (x <= new_line.point2[0])
    {
        mlx_pixel_put(mlx_pnt, win_pnt, x, y, color);
        if (p >= 0)
        {
            y += new_line.slope;
            p -= 2 * new_line.dx;
        }
        else
        {
            x++;
            p += 2 * new_line.dy;
        }
    }
}

void new_segment(s_line *segment, int pt1[2], int pt2[2])
{
    int *start;
    int *end;

    if (pt1[0] <= pt2[0])
    {
        start = pt1;
        end = pt2;
    }
    else
    {
        start = pt2;
        end = pt1;
    }
    segment->point1 = start;
    segment->point2 = end;
    segment->dx = abs(segment->point1[0] - segment->point2[0]);
    segment->dx = segment->dx > 0 ? segment->dx : 1;
    segment->dy = abs(segment->point1[1] - segment->point2[1]);
    segment->slope = segment->point2[1] - segment->point1[1] > 0 ? 1 : -1;
    segment->m = (float)segment->dy / segment->dx;
}

int key_hook(int keycode, s_drawinfo *draw_info)
{
    s_line new_line;
    static int y = 300;
    int pt1[2] = {10, y};
    int pt2[2] = {300, 10};

    new_segment(&new_line, pt1, pt2);
    y -= 10;
    if (keycode == SPACE)
        drawline(new_line, draw_info->mlx_pnts->mlx_pnt , draw_info->mlx_pnts->win_pnt, draw_info->map_info->colors[1]);
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
        free(map_info->map_array[i++]);
    free(map_info->map_array);
}

int main(int argc, char **argv)
{
    s_mlx_pnts mlx_pnts;
    int pt1[2] = {10, 400};
    int pt2[2] = {300, 10};
    s_line new_line;
    s_map map_info;
    char *str;
    s_drawinfo draw_info;
    s_img img;
    s_position pos_info;


    init_map_info(&map_info);
    if (argc == 3)
    {
        if (ft_strcmp(argv[1], "-m") == 0)
        {
            int ret = parse_file(argv[2], &map_info);
            //for debigging. normally invalid map vs valid map
            if (ret == -1)
                printf("Error reading file\n");
            else if (ret == 0)
            {
                printf("Valid Map\n");
                set_up_pos_info(&pos_info, &map_info);
                printf("Camera: %f %f\n",pos_info.camera_plane[0], pos_info.camera_plane[1]);
                printf("Direction: %f %f\n",pos_info.cur_direction[0], pos_info.cur_direction[1]);
                printf("Position: %f %f\n",pos_info.cur_position[0], pos_info.cur_position[1]);
            }
            else if (ret == -2)
                printf("Outside of map must be 1's\n");
            else if (ret == -3)
                printf("Player rotation must be present once within inside of map\n");
            else if (ret == -4)
                printf("Invalid characters in map\n");
            else if (ret == -5)
                printf("Invalid form\n");
            // printf("%d %d\n", map_info.colors[0], map_info.colors[1]);
            free_map_info(&map_info);
        }
    }
    //wrap whole thing in infinite loop - how works with mlx loop?

    /*
    set_up_pnts(&mlx_pnts, &map_info);
    new_segment(&new_line, pt1, pt2);
    // drawline(new_line, mlx_pnts.mlx_pnt, mlx_pnts.win_pnt, map_info.colors[0]);
    draw_info.map_info = &map_info;
    draw_info.mlx_pnts = &mlx_pnts;
    mlx_key_hook(mlx_pnts.win_pnt, key_hook, (void *)&draw_info);
    // img = ratio_image(&draw_info, "Images/302Sableye.xpm", .99);
    img = tile_image(&draw_info, "Images/bluestone.xpm", 2, 2);
    printf("w: %d h: %d\n", img.width, img.height);
    mlx_put_image_to_window(mlx_pnts.mlx_pnt, mlx_pnts.win_pnt, img.img_pnt, 0, 100);
    s_img new_img;
    s_trap_img_dimen trap_dimen;
    trap_dimen.start_len = 250;
    trap_dimen.end_len = 20;
    trap_dimen.new_width = 600;
    new_img = make_trapezoid_image(&draw_info, img, trap_dimen);
    mlx_put_image_to_window(mlx_pnts.mlx_pnt, mlx_pnts.win_pnt, new_img.img_pnt, 0, 200);
    mlx_destroy_image(mlx_pnts.mlx_pnt, img.img_pnt);
    mlx_loop(mlx_pnts.mlx_pnt); */
}