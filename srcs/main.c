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

int key_hook(int keycode, s_mlx_pnts *pnts)
{
    s_line new_line;
    static int y = 300;
    int pt1[2] = {10, y};
    int pt2[2] = {300, 10};
    
    new_segment(&new_line, pt1, pt2);
    y -= 10;
    if (keycode == SPACE)
        drawline(new_line, pnts->mlx_pnt, pnts->win_pnt, 0xB0EACF);
    return keycode;
}

void set_up_pnts(s_mlx_pnts *pnts)
{
    pnts->mlx_pnt = mlx_init();
    pnts->win_pnt = mlx_new_window(pnts->mlx_pnt, 500, 500, "Title");
}

// void set_pnts(s_map *map_info)
// {
//     map_info->R = &map_info->pnt_array[0];
//     map_info->NO = &map_info->pnt_array[1];
//     map_info->SO = &map_info->pnt_array[2];
//     map_info->WE = &map_info->pnt_array[3];
//     map_info->EA = &map_info->pnt_array[4];
//     map_info->S = &map_info->pnt_array[5];
//     map_info->F = &map_info->pnt_array[6];
//     map_info->C = &map_info->pnt_array[7];
// }

void free_map_info(s_map *map_info)
{
    if (map_info->R)
        free(map_info->R);
    if (map_info->NO)
        free(map_info->NO);
    if (map_info->SO)
        free(map_info->SO);
    if (map_info->WE)
        free(map_info->WE);
    if (map_info->EA)
        free(map_info->EA);
    if (map_info->S)
        free(map_info->S);
    if (map_info->F)
        free(map_info->F);
    if (map_info->C)
        free(map_info->C);
    if (map_info->map)
        free(map_info->map);
}

int main(int argc, char **argv)
{
    s_mlx_pnts mlx_pnts;
    int pt1[2] = {10, 400};
    int pt2[2] = {300, 10};
    s_line new_line;
    s_map map_info;
    char *str;

    str = malloc(100);
    if (argc == 3)
    {
        if (ft_strcmp(argv[1], "-m") == 0)
        {
            int ret = parse_file(argv[2], &map_info);
            if (ret == -1)
                printf("Error reading file");
            else
            {
                printf("Read successfully");
            }
            free_map_info(&map_info);
        }
    }
    // set_up_pnts(&mlx_pnts);
    // new_segment(&new_line, pt1, pt2);
    // drawline(new_line, mlx_pnts.mlx_pnt, mlx_pnts.win_pnt, 0xB0EACF);
    // mlx_key_hook(mlx_pnts.win_pnt, key_hook, (void *)&mlx_pnts);
    // mlx_loop(mlx_pnts.mlx_pnt);
}