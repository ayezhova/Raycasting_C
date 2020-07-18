#ifndef RAYCASTING
#define RAYCASTING

#include <fcntl.h>
#include "../GNL/get_next_line.h"
#include <stdio.h> /* DEL */
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include "../libft/libft.h"


/* Constants for Move/Rotate */
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.1

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
    int **map_int_array;
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
    int bit_size;
    int line_orig;
    int line_new;
    int next_skip_col;
    int length_skip;
    float pix_change;
} s_img_iter;

typedef struct t_trap_img_dimen
{
    int start_len;
    int end_len;
    int new_width;
} s_trap_img_dimen;

typedef struct t_trap_image
{
    int col_orig;
    int col_new;
    int start_line;
    int col_height;
} s_trap_image;

typedef struct t_position
{
    float cur_position[2];
    float cur_direction[2];
    float camera_plane[2];
} s_position;

/* Calculating distance */
typedef struct t_dist_calc
{
    float camera_loc;
    float ray_dir[2];
    int map_loc[2];
    float dist_next_x;
    float dist_next_y;
    float change_in_x;
    float change_in_y;
    int step_dir[2];
    int side_hit;
    float dist_to_wall;
    int line_height;
    int row_start;
    int row_stop;
} s_dist_calc;

typedef struct t_key_arg
{
    s_map *map_info;
    s_position *pos;
    s_mlx_pnts *mlx_pnts;
    char **map_array;
} s_key_arg;

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
int **map_int_array(char **map_array);

/* Set up direction and camera variables */
void set_up_pos_info(s_position *pos_info, s_map *map_info);

/* Put Image */
s_img ratio_image(s_drawinfo *drawinfo, char *img_path, float ratio);
void set_img_colors_small(s_img orig_img, s_img new_img, int ratio);
s_img tile_image(s_drawinfo *drawinfo, char *img_path, float x_times, float y_times);
int val_small(s_img img, s_img_iter s_i, int orig);
int val(s_img img, int line, int  bit, int k);

/* Manipulate image into trapezoid shape */
s_img make_trapezoid_image(s_drawinfo *drawinfo, s_img orig_img, s_trap_img_dimen trap_dimen);
void draw_line_longer(s_img orig_img, s_img new_img, s_trap_image s_t_i);
void draw_line_shorter(s_img orig_img, s_img new_img, s_trap_image s_t_i);
void get_col_height(s_img *img, s_trap_img_dimen dimen,
    s_trap_image *s_t_i, float height_change);
float get_constant(int width_orig, int width_new);


/* Draw Screen */
void draw_screen(s_map *map_info, s_position *pos, s_mlx_pnts *mlx_pnts);
void new_segment(s_line *segment, int pt1[2], int pt2[2]);
void drawline(s_line new_line, s_mlx_pnts *mlx_pnts, int color);
void drawcol(int col, s_dist_calc *dist, s_mlx_pnts *mlx_pnts, int color);



/* MOVE TO LIBFT */
int abs(int a);
float ft_fabs(float a);

/* KEY EVENTS */
void move_up(int **map, s_position *pos);
void move_down(int **map, s_position *pos);
void rotate_right(int **map, s_position *pos);
void rotate_left(int **map, s_position *pos);

#endif