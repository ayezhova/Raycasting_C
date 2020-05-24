#ifndef RAYCASTING
#define RAYCASTING

#include <fcntl.h>
#include "../GNL/get_next_line.h"
#include <stdio.h>
// #include "../minilibx_macos/mlx.h"
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
    // int width;
} s_map;


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
// int get_map(char *map_file, s_map *map_info);
int parse_file(char *map_file, s_map *map_info);
int check_map_valid(s_map *map_info);
int check_inputs(s_map *map_info);

#endif