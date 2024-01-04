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
}   t_img;


#endif