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

typedef struct t_map
{
    int R_x;
    int R_y;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    char *S;
    int F_RGB[3];
    int C_RGB[3];
    char *full_file;
    char *map;
    int height;
    int width;
} s_map;


/* Key Codes */
# define SPACE 49
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

/* Additional Functions */
int get_next_line(const int fd, char **line);
int check_map_valid(s_map *map_info);
int get_map(char *map_file, s_map *map_info);

#endif