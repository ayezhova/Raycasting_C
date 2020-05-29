#include "raycasting.h"

int val(s_img img, int line, int  bit, int k)
{
    int bits_size;

    bits_size = img.size_line / img.width;
    return line * img.size_line + k * bits_size + bit;
}

void set_img_colors_smaller(s_img orig_img, s_img new_img, int ratio)
{
    int i;
    int j;
    int bit;
    int line;

    line = -1;
    while (++line < orig_img.height && (int)(line / ratio) < new_img.height)
    {
        if (line % ratio == 0)
        {
            i = -1;
            j = 0;
            while (++i < orig_img.width)
            {
                if (i % ratio == 0)
                {
                    bit = -1;
                    while (++bit < (orig_img.size_line / orig_img.width))
                        new_img.mem_address[val(new_img, line / ratio, bit, j)] =
                            orig_img.mem_address[val(orig_img, line, bit, i)];
                    j++;
                }
            }
        }
    }
}

s_img ratio_image(s_drawinfo *drawinfo, char *img_path, float ratio)
{
    s_img orig_img;
    s_img new_img;

    new_img.img_pnt = NULL;
    if (!(orig_img.img_pnt = mlx_xpm_file_to_image(drawinfo->mlx_pnts->mlx_pnt,
        img_path, &orig_img.width, &orig_img.height)))
        return new_img;
    orig_img.mem_address = mlx_get_data_addr(orig_img.img_pnt,
        &orig_img.bits_per_pixel, &orig_img.size_line, &orig_img.endian);
    new_img.width = (int)(orig_img.width * ratio);
    new_img.height = (int)(orig_img.height * ratio);
    new_img.img_pnt = mlx_new_image(drawinfo->mlx_pnts->mlx_pnt,
        new_img.width, new_img.height);
    new_img.mem_address = mlx_get_data_addr(new_img.img_pnt,
        &new_img.bits_per_pixel, &new_img.size_line, &new_img.endian);
    if (ratio < 1 && ratio > .5)
        set_img_colors_small(orig_img, new_img, (int)(10 * ratio));
    else if (ratio <= .5)
        set_img_colors_smaller(orig_img, new_img, (int)(1 / ratio));
    mlx_destroy_image(drawinfo->mlx_pnts->mlx_pnt, orig_img.img_pnt);
    return new_img;
}
