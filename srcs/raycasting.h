#ifndef RAYCASTING
#define RAYCASTING

#include <fcntl.h>
#include "../GNL/get_next_line.h"
#include <stdio.h>
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"

typedef struct t_mlx_pnts
{
    void *mlx_pnt;
    void *win_pnt;
} s_mlx_pnts;

typedef struct t_line
{
    int *point1;
    int *point2;
    int dx;
    int dy;
    int slope;
    float m;
} s_line;

/* Amount of map info expcting to get*/
# define MAP_VAR 8

typedef struct t_map
{
    int R_x;
    int R_y;
    int start[2];
    char orientation;
    char *pnt_array[MAP_VAR];
    char **expected;
    int data_given[MAP_VAR];
    char **R;
    char **NO;
    char **SO;
    char **WE;
    char **EA;
    char **S;
    char **F;
    char **C;
    int colors[2];
    char *map;
    char **map_array;
    int height;
} s_map;

typedef struct t_drawinfo
{
    s_map *map_info;
    s_mlx_pnts *mlx_pnts;
} s_drawinfo;

/* Image struct */
typedef struct t_img
{
    void *img_pnt;
    int width;
    int height;
    int bits_per_pixel;
    int size_line;
    int endian;
    char *mem_address;
} s_img;

typedef struct t_img_iter
{
    int i;
    int j;
    int bit;
    int line;
    int line2;
    int next_skip_col;
    int length_skip;
} s_img_iter;

/* Key Codes */
# define SPACE 49
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

/* Additional Functions */

/* Reading file */
int get_next_line(const int fd, char **line);
int check_map_valid(s_map *map_info);
int parse_file(char *map_file, s_map *map_info);
int check_map_valid(s_map *map_info);
int check_inputs(s_map *map_info);

/* Put Image */
s_img ratio_image(s_drawinfo *drawinfo, char *img_path, float ratio);
void set_img_colors_small(s_img orig_img, s_img new_img, int ratio);

#endif