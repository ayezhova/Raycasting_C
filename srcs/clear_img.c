#include "raycasting.h"

void clear_img(s_img *img)
{
    int row;
    int col;

    row = 0;
    while (row < img->height)
    {
        col = 0;
        while (col < img->size_line)
        {
            img->mem_address[row * img->size_line + col] = 0;
            col++;
        }
        row++;
    }
}
