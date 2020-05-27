#include "raycasting.h"

void *put_image(s_drawinfo *drawinfo)
{
    void *img_pnt;
    int width;
    int height;
    int bits_per_pixel;
    int size_line;
    int endian;
    char *mem_address;


    width = 50;
    height = 50;
    if (!(img_pnt = mlx_xpm_file_to_image(drawinfo->mlx_pnts->mlx_pnt, "Images/302Sableye.xpm", &width, &height)))
    {
        printf("IMG NULL\n");
        return NULL;
    }
    mem_address = mlx_get_data_addr(img_pnt, &bits_per_pixel, &size_line, &endian );
    mlx_put_image_to_window(drawinfo->mlx_pnts->mlx_pnt, drawinfo->mlx_pnts->win_pnt, img_pnt, 0, 0);
    mlx_put_image_to_window(drawinfo->mlx_pnts->mlx_pnt, drawinfo->mlx_pnts->win_pnt, img_pnt, 100, 100);
    return img_pnt;
}