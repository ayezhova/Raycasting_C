#include "raycasting.h"

void move_up(int **map, s_position *pos)
{
    float next_x;
    float next_y;

    next_x = pos->cur_position[0] + pos->cur_direction[0] * MOVE_SPEED;
    next_y = pos->cur_position[1] + pos->cur_direction[1] * MOVE_SPEED;
    if (map[(int)next_x][(int)pos->cur_position[1]] == 0)
        pos->cur_position[0] = next_x;
    if (map[(int)pos->cur_position[0]][(int)next_y] == 0)
    {
        pos->cur_position[1] = next_y;
    }
}

void move_down(int **map, s_position *pos)
{
    float next_x;
    float next_y;

    next_x = pos->cur_position[0] - pos->cur_direction[0] * MOVE_SPEED;
    next_y = pos->cur_position[1] - pos->cur_direction[1] * MOVE_SPEED;
    if (map[(int)next_x][(int)pos->cur_position[1]] == 0)
        pos->cur_position[0] = next_x;
    if (map[(int)pos->cur_position[0]][(int)next_y] == 0)
    {
        pos->cur_position[1] = next_y;
    }
}

void rotate_right(int **map, s_position *pos)
{
    float prev_dir_x;
    float prev_camera_x;

    prev_dir_x = pos->cur_direction[0];
    prev_camera_x = pos->camera_plane[0];
    pos->cur_direction[0] = prev_dir_x * cos(-1 * ROT_SPEED)
        - pos->cur_direction[1] * sin(-1 * ROT_SPEED);
    pos->cur_direction[1] = prev_dir_x * sin(-1 * ROT_SPEED)
        + pos->cur_direction[1] * cos(-1 * ROT_SPEED);
    pos->camera_plane[0] = prev_camera_x * cos(-1 * ROT_SPEED)
        - pos->camera_plane[1] * sin(-1 * ROT_SPEED);
    pos->camera_plane[1] = prev_camera_x * sin(-1 * ROT_SPEED)
        + pos->camera_plane[1] * cos(-1 * ROT_SPEED);
}

void rotate_left(int **map, s_position *pos)
{
    float prev_dir_x;
    float prev_camera_x;

    prev_dir_x = pos->cur_direction[0];
    prev_camera_x = pos->camera_plane[0];
    pos->cur_direction[0] = prev_dir_x * cos(ROT_SPEED)
        - pos->cur_direction[1] * sin(ROT_SPEED);
    pos->cur_direction[1] = prev_dir_x * sin(ROT_SPEED)
        + pos->cur_direction[1] * cos(ROT_SPEED);
    pos->camera_plane[0] = prev_camera_x * cos(ROT_SPEED)
        - pos->camera_plane[1] * sin(ROT_SPEED);
    pos->camera_plane[1] = prev_camera_x * sin(ROT_SPEED)
        + pos->camera_plane[1] * cos(ROT_SPEED);
}
