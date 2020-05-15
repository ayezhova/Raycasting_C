#include <mlx.h>
#include <stdio.h>
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

int key_hook(int keycode, void *param)
{
    s_line new_line;
    int pt1[2] = {10, 200};
    int pt2[2] = {300, 10};
    
    new_segment(&new_line, pt1, pt2);

    if (keycode == SPACE)
        drawline(new_line, param[0], param[1], 0xB0EACF);
    return keycode;
}

int main()
{
    void *mlx_pnt;
    void *win_pnt;
    int pt1[2] = {10, 400};
    int pt2[2] = {300, 10};
    s_line new_line;

    new_segment(&new_line, pt1, pt2);
    mlx_pnt = mlx_init();
    win_pnt = mlx_new_window (mlx_pnt, 500, 500, "Title");
    drawline(new_line, mlx_pnt, win_pnt, 0xB0EACF);
    mlx_key_hook(win_pnt, key_hook, {mlx_pnt, win_pnt});
    mlx_loop(mlx_pnt);
}