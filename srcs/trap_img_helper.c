#include "raycasting.h"

void get_col_height(s_img *img, s_trap_img_dimen dimen,
    s_trap_image *s_t_i, float height_change)
{
    if (dimen.start_len > dimen.end_len)
        s_t_i->col_height = img->height -
        (int)(s_t_i->col_new * height_change);
    else 
        s_t_i->col_height = img->height -
        (int)((img->width - s_t_i->col_new) * height_change);
    s_t_i->start_line = (img->height - s_t_i->col_height) / 2;
}


void set_mem_address(s_img *orig_img, s_img *new_img, s_img_iter s_i, s_trap_image s_t_i)
{
    new_img->mem_address[(s_i.line_new + s_t_i.start_line) * new_img->size_line +
        s_t_i.col_new * s_i.bit_size + s_i.bit] = 
        orig_img->mem_address[s_i.line_orig * orig_img->size_line +
        s_t_i.col_orig * s_i.bit_size + s_i.bit];
}

// void set_transparent(s_img *img, s_trap_image s_t_i)
// {
//     int line;
//     int bit;
//     int bit_size;
//     int i;

//     bit_size = img->size_line / img->width;
//     i = 0;
//     line = 0;
//     while (line < s_t_i.start_line)
//     {
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 1] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 2] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 3] = -1;
//         line++;
//     }
//     line += s_t_i.col_height;
//     while (line < img->height)
//     {
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 1] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 2] = 0;
//         img->mem_address[line * img->size_line + s_t_i.col_new * bit_size + 3] = -1;
//         line++;
//     }
// }

void draw_line_shorter(s_img orig_img, s_img new_img, s_trap_image s_t_i)
{
    s_img_iter s_i;
    float next_skip_line;
    float skip_change;
    
    s_i.line_new = 0;
    s_i.line_orig = 0;
    s_i.bit_size = orig_img.size_line / orig_img.width;
    skip_change = (float) orig_img.height /
        (orig_img.height - s_t_i.col_height);
    next_skip_line = skip_change;
    // set_transparent(&new_img, s_t_i);
    while(s_i.line_new < s_t_i.col_height)
    {
        if (s_i.line_orig + 1 != (int)next_skip_line)
        {
            s_i.bit = -1;
            while (++s_i.bit < s_i.bit_size)
                set_mem_address(&orig_img, &new_img, s_i, s_t_i);
            s_i.line_new++;
        }
        else
            next_skip_line += skip_change;
        s_i.line_orig++;
    }
}

void draw_line_longer(s_img orig_img, s_img new_img, s_trap_image s_t_i)
{
    float write_change;
    float left2write;
    s_img_iter s_i;

    s_i.line_new = 0;
    s_i.line_orig = 0;
    write_change = s_t_i.col_height / (float) orig_img.height;
    left2write = write_change;
    s_i.bit_size = orig_img.size_line / orig_img.width;
    while (s_i.line_new < s_t_i.col_height)
    {
        s_i.bit = -1;
        while (++s_i.bit < s_i.bit_size)
            set_mem_address(&orig_img, &new_img, s_i, s_t_i);
        left2write--;
        if (left2write < 1)
        {
            left2write += write_change;
            s_i.line_orig++;
        }
        s_i.line_new++;
    }
}