/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:03:31 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/07 22:10:20 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

typedef struct s_img
{
	void	*mlx;
	void	*win;
	void	*imgb;
	void	*imgp;
	void	*imgc;
	void	*imgw;
	void	*imgd;
	char	*mapp;
	int		move;
	int		x;
	int		y;
	int		fd;
	int		y_p;
	int		x_p;
	int		old_plx;
	int		old_ply;
}	t_img;

void	ft_error(char *s);
char	**ft_split(char const *s, char c);
size_t	ft_strlenn(const char *str);
char	*ft_itoa(int n);
void	ft_check_map(t_img *img, int i, int j);
void	ft_show(t_img *img, int n);
int		key_press(int keycode, t_img *img);
void	ft_start(t_img *img, int w_b, int h_b);
void	ft_read_map(t_img *img, int *i, int *j, char *str);
void	look_for_err_map(char *s);
void	ft_putnbr_fd(int n, int fd);

char	*get_next_line(int fd);
char	*ft_strdup(char *s1, int b);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
int		new_line_check(char *str, int *len);
void	ft_free_arr(char **arr);
void	ft_des_img(t_img *img);
int		ft_cross(t_img *img);
void	ft_setzero(t_img *img);

#endif