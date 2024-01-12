#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

// typedef struct s_en
// {
//     int en_x;
//     int en_y;
//     int positon;
// }t_en;

typedef struct s_img
{
    void *mlx;
    void *win;
    void *imgb;
    void *imgp;
    void *imgc;
    void *imgw;
    void *imgd;
    void *imgcd;
    void *enmy;
    void *pr;
    void *pu;
    void *pl;
    void *pd;
    char *mapp;
    int move;
    int x;
    int y;
    int fd;

    int y_p;
    int x_p;
    int old_plx;
    int old_ply;
}   t_img;




char	**ft_split(char const *s, char c);
size_t	ft_strlenn(const char *str);
char	*ft_itoa(int n);
int ft_check_map(t_img *img, int i, int j);
void ft_show(t_img *img, int n, int key_c);
int key_press(int keycode, t_img *img);
void ft_start(t_img *img,int w_b, int h_b);
int ft_helper(t_img *img, int *i, int *j);

#endif