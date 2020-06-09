#include "raycasting.h"

void trap_dec_shorter(s_img orig_img, s_img new_img, s_trap_img_dimen dimen)
{
    s_trap_image s_t_i;
    float height_change;
    float skip_change;
    float next_skip_col;

    s_t_i.col_orig = 0;
    s_t_i.col_new = 0;
    height_change = abs(dimen.start_len - dimen.end_len) /
        (float)new_img.width;
    skip_change = (float)orig_img.width / new_img.width;
    while(s_t_i.col_new < new_img.width)
    {
        get_col_height(&new_img, dimen, &s_t_i, height_change);
        if (s_t_i.col_orig + 1 != (int)next_skip_col) {
            if (s_t_i.col_height >= orig_img.height)
                draw_line_longer(orig_img, new_img, s_t_i);
            else if (s_t_i.col_height < orig_img.height)
                draw_line_shorter(orig_img, new_img, s_t_i);
            s_t_i.col_new++;
        }
        else
            next_skip_col += skip_change;
        s_t_i.col_orig++;
    }
}

void trap_dec_longer(s_img orig_img, s_img new_img, s_trap_img_dimen dimen)
{
    s_trap_image s_t_i;
    float height_change;
    float write_change;
    float left2write;

    s_t_i.col_orig = 0;
    s_t_i.col_new = -1;
    height_change = abs(dimen.start_len - dimen.end_len) /
        (float)new_img.width;
    write_change = (float)new_img.width / orig_img.width;
    while(++s_t_i.col_new < new_img.width)
    {
        get_col_height(&new_img, dimen, &s_t_i, height_change);
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
    if (new_img.width >= orig_img.width)
        trap_dec_longer(orig_img, new_img, trap_dimen);
    else
        trap_dec_shorter(orig_img, new_img, trap_dimen);
    return new_img;
}
