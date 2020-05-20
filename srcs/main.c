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

int main(int argc, char **argv)
{
    s_mlx_pnts mlx_pnts;
    int pt1[2] = {10, 400};
    int pt2[2] = {300, 10};
    s_line new_line;
    s_map map_info;

    if (argc == 3)
    {
        if (ft_strcmp(argv[1], "-m") == 0)
        {
            if (!get_map(argv[2], &map_info))
                return 0;
            printf("%d\n", check_map_valid(&map_info));
            free(map_info.full_file);
        }
    }
    set_up_pnts(&mlx_pnts);
    new_segment(&new_line, pt1, pt2);
    drawline(new_line, mlx_pnts.mlx_pnt, mlx_pnts.win_pnt, 0xB0EACF);
    mlx_key_hook(mlx_pnts.win_pnt, key_hook, (void *)&mlx_pnts);
    mlx_loop(mlx_pnts.mlx_pnt);
}