#ifndef RAYCASTING
#define RAYCASTING

typedef struct t_line
{
    int *point1;
    int *point2;
    int dx;
    int dy;
    int slope;
    float m;
} s_line;

/* Key Codes */
# define SPACE 49
# define ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define UP_ARROW 126

#endif