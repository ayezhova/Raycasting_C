#include "raycasting.h"

void set_mem_address(s_img *orig_img, s_img *new_img, s_img_iter s_i, s_trap_image s_t_i)
{
    new_img->mem_address[(s_i.line_new + s_t_i.start_line) * new_img->size_line +
        s_t_i.col_new * s_i.bit_size + s_i.bit] = 
        orig_img->mem_address[s_i.line_orig * orig_img->size_line +
        s_t_i.col_orig * s_i.bit_size + s_i.bit];
}

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


void trap_dec_longer(s_img orig_img, s_img new_img, s_trap_img_dimen dimen)
{
    s_trap_image s_t_i;
    float height_change;
    float write_change;
    float left2write;

    s_t_i.col_orig = 0;
    s_t_i.col_new = 0;
    height_change = abs(dimen.start_len - dimen.end_len) /
        (float)new_img.width;
    write_change = (float)new_img.width / orig_img.width;
    while(s_t_i.col_new < new_img.width)
    {
        s_t_i.col_height = new_img.height - (int)(s_t_i.col_new * height_change);
        s_t_i.start_line = (new_img.height - s_t_i.col_height) / 2;
        if (s_t_i.col_height >= orig_img.height)
            draw_line_longer(orig_img, new_img, s_t_i);
        else if (s_t_i.col_height < orig_img.height)
            draw_line_shorter(orig_img, new_img, s_t_i);
        left2write--;
        if (left2write < 1)
        {
            left2write += write_change;
            s_t_i.col_orig++;
        }
        s_t_i.col_new++;
    }

}

s_img make_trapezoid_image(s_drawinfo *drawinfo, s_img orig_img, s_trap_img_dimen trap_dimen)
{
    s_img new_img;

    new_img.height = ft_max(trap_dimen.start_len, trap_dimen.end_len);
    new_img.width = trap_dimen.new_width;
    new_img.img_pnt = mlx_new_image(drawinfo->mlx_pnts->mlx_pnt,
        new_img.width, new_img.height);
    new_img.mem_address = mlx_get_data_addr(new_img.img_pnt,
        &new_img.bits_per_pixel, &new_img.size_line, &new_img.endian);
    if (trap_dimen.start_len >= trap_dimen.end_len)
    {
        if (new_img.width >= orig_img.width)
            trap_dec_longer(orig_img, new_img, trap_dimen);
    }
    return new_img;
}
