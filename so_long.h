#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

typedef struct s_img
{
    void *mlx;
    void *win;
    void *imgb;
    void *imgp;
    void *imgc;
    void *imgw;
    char *mapp;
    int x;
    int y;
    int fd;
    int y_p;
    int x_p;
    int old_plx;
    int old_ply;
}   t_img;
typedef struct s_player
{
    void *imgp;
    int x;
    int y;
}   t_player;
typedef struct s_background
{
    void *imgc;
    int x;
    int y;
}   t_background;
typedef struct s_coin
{
    void *imgc;
    int x;
    int y;
}   t_coin;



#endif