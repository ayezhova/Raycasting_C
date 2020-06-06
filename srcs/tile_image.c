#include "raycasting.h"

void set_tile_bit(s_img_iter *s_i, s_img *orig_img, s_img *new_img)
{
    int bit_size;

    bit_size = orig_img->size_line / orig_img->width;
    s_i->bit = -1;
    while (++s_i->bit < bit_size)
        new_img->mem_address[s_i->line_new * new_img->size_line +
            s_i->j * bit_size + s_i->bit] =
            orig_img->mem_address[s_i->line_orig * orig_img->size_line +
            s_i->i * bit_size + s_i->bit];
    s_i->line_new += orig_img->height;
}

void set_tile_colors(s_img orig_img, s_img new_img)
{
    s_img_iter s_i;

    s_i.line_orig = -1;
    while (++s_i.line_orig < orig_img.height)
    {
        s_i.i = -1;
        while(++s_i.i < orig_img.width)
        {
            s_i.j = s_i.i;
            while (s_i.j < new_img.width)
            {
                s_i.line_new = s_i.line_orig;
                while (s_i.line_new < new_img.height)
                    set_tile_bit(&s_i, &orig_img, &new_img);
                s_i.j += orig_img.width;
            }
        }
    }
}

s_img tile_image(s_drawinfo *drawinfo, char *img_path, float x_times, float y_times)
{
    s_img orig_img;
    s_img new_img;

    new_img.img_pnt = NULL;
    if (!(orig_img.img_pnt = mlx_xpm_file_to_image(drawinfo->mlx_pnts->mlx_pnt,
        img_path, &orig_img.width, &orig_img.height)))
        return new_img;
    orig_img.mem_address = mlx_get_data_addr(orig_img.img_pnt,
        &orig_img.bits_per_pixel, &orig_img.size_line, &orig_img.endian);
    new_img.width = (int)(orig_img.width * x_times);
    new_img.height = (int)(orig_img.height * y_times);
    new_img.img_pnt = mlx_new_image(drawinfo->mlx_pnts->mlx_pnt,
        new_img.width, new_img.height);
    new_img.mem_address = mlx_get_data_addr(new_img.img_pnt,
        &new_img.bits_per_pixel, &new_img.size_line, &new_img.endian);
    set_tile_colors(orig_img, new_img);
    mlx_destroy_image(drawinfo->mlx_pnts->mlx_pnt, orig_img.img_pnt);
    return new_img;
}