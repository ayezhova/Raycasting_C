#include "raycasting.h"

void init_back_info(s_background *back_info, s_map *map_info)
{
    back_info->col = 0;
    back_info->color_ceil = map_info->colors[0];
    back_info->color_ground = map_info->colors[1];
}

void set_color(s_img *new_img, int color, int col, int y)
{
    new_img->mem_address[y * new_img->size_line
        + col * new_img->bits_per_pixel] = color & 255;
    new_img->mem_address[y * new_img->size_line
        + col * new_img->bits_per_pixel + 1] = color >> 8 & 255;
    new_img->mem_address[y * new_img->size_line
        + col * new_img->bits_per_pixel + 2] = color >> 16 & 255;
}

void set_text_color(s_background *back_info, s_img *new_img, s_img *texture)
{
    int bit;

    bit = 0;
    while (bit < new_img->bits_per_pixel)
    {
        new_img->mem_address[back_info->row * new_img->size_line
            + back_info->col * new_img->bits_per_pixel + bit] =
            texture->mem_address[(int)back_info->text_y * texture->size_line
            + back_info->text_x * texture->bits_per_pixel + bit];
        bit++;
    }
}


void init_text_x(s_background *back_info, s_dist_calc *dist, s_img *texture)
{
    back_info->text_x = (int)((dist->exact_hit - 
        (int)dist->exact_hit) * texture->width);
    if ((dist->side_hit == 0 && dist->ray_dir[0] > 0) ||
        (dist->side_hit == 1 && dist->ray_dir[1] < 0))
        back_info->text_x = texture->width - back_info->text_x - 1;
}

void add_col_to_image(s_background *back_info, s_dist_calc *dist,
    s_img *new_img, s_img *texture)
{
    float step;
    int bit;

    init_text_x(back_info, dist, texture);
    step = (float)(texture->height) / dist->line_height;
    back_info->text_y = 0.0;
    back_info->row = 0;
    while (back_info->row < dist->row_start)
        set_color(new_img, back_info->color_ceil, back_info->col, back_info->row++);
    while (back_info->row < dist->row_stop)
    {
        set_text_color(back_info, new_img, texture);
        back_info->text_y += step;
        back_info->row++;
    }
    while (back_info->row < new_img->height)
        set_color(new_img, back_info->color_ground, back_info->col, back_info->row++);
    back_info->col++;
}
