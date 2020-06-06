#include "raycasting.h"

int val_small(s_img img, s_img_iter s_i, int orig)
{
    int bits_size;

    bits_size = img.size_line / img.width;
    if (orig)
        return s_i.line_orig * img.size_line + s_i.i * bits_size + s_i.bit;
    return  s_i.line_new * img.size_line + s_i.j * bits_size + s_i.bit;
}

void set_row(s_img_iter *s_i, int length_skip, s_img orig_img, s_img new_img)
{
    s_i->i = -1;
    s_i->j = 0;
    s_i->next_skip_col = length_skip;
    while (++s_i->i < orig_img.width)
    {
        if (s_i->i + 1 == (int)s_i->next_skip_col)
            s_i->next_skip_col += length_skip;
        else
        {
            s_i->bit = -1;
            while (++s_i->bit < (orig_img.size_line / orig_img.width))
                new_img.mem_address[val_small(new_img, *s_i, 0)] =
                    orig_img.mem_address[val_small(orig_img, *s_i, 1)];
            s_i->j++;
        }
    }
    s_i->line_new++;
}

void set_img_colors_small(s_img orig_img, s_img new_img, int ratio)
{
    float length_skip;
    s_img_iter s_i;
    float next_skip_row;
    
    s_i.line_orig = -1;
    s_i.line_new = 0;
    length_skip = 10.0 / (10 - ratio);
    next_skip_row = length_skip;
    s_i.next_skip_col = length_skip;
    while (++s_i.line_orig < orig_img.height)
    {
        if (s_i.line_orig + 1 == (int)next_skip_row)
            next_skip_row += length_skip;
        else
        {
            set_row(&s_i, length_skip, orig_img, new_img);
        }
    }
}
