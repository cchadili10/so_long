/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/01/07 17:18:23 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_foof_fill(char **arr)
{
	
}
int ft_check_map(t_img *img, int i, int j)
{
	char **arr = ft_split(img->mapp, '\n');
	int x = 0;
	int y = 0;
	int check = 0;
	int check_E = 0;
	while (arr[0][x])
	{
		if(arr[0][x] != '1' || arr[i-1][x] != '1')
			return 1;
		x++;
	}
	while (arr[y])
	{
		if(arr[y][0] != '1' || arr[y][j-1] != '1')
			return 1;
		y++;
	}
	x = 0;
	y = 0;
	while (img->mapp[x])
	{
		if(img->mapp[x] != 'P' && img->mapp[x] != 'E' && img->mapp[x] != '0' && img->mapp[x] != '1' && img->mapp[x] != 'C' && img->mapp[x] != '\n')
			return 1;
		if(img->mapp[x] == 'P')
			y++;
		if(img->mapp[x] == 'E')
			check_E++;
		if(img->mapp[x] == 'C')
			check++;
		x++;
	}
	if(y != 1 || check_E != 1 || check < 1)
	{
		printf("%d \t %d\t %d",y,check_E,check);
		return 1;
	}
	ft_foof_fill(arr);
	return 0;
}
int look_for_coin(char *s)
{
	int x = 0;
	while (s[x])
	{
		if(s[x] == 'C')
			return 1;
		x++;
	}
	return 0;
}
void ft_show(t_img *img, int n)
{
	int x = 0;
	int old_x;
	int old_y;
	while (img->mapp[x])
	{
		if (img->mapp[x] == '1')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgw, img->x, img->y);
			old_x = img->x;
			old_y = img->y;
		}
		else if (img->mapp[x] == 'P' && n)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->x, img->y);
			img->x_p = img->x;
			img->y_p = img->y;
		}
		else if (img->mapp[x] == 'E')
		{
			if(look_for_coin(img->mapp))
				mlx_put_image_to_window(img->mlx, img->win, img->imgd, img->x, img->y);
			else if(look_for_coin(img->mapp) == 0)
			{
				mlx_put_image_to_window(img->mlx, img->win, img->imgcd, img->x, img->y);
				if(img->x == img->x_p && img->y == img->y_p)
					exit(0);
			}
		}
		else if (img->mapp[x] == 'C' && (img->x_p != img->x || img->y_p != img->y))
			mlx_put_image_to_window(img->mlx, img->win, img->imgc, img->x, img->y);
		else if (img->mapp[x] == 'C' && (img->x_p == img->x && img->y_p== img->y))
			img->mapp[x] = '0';
		else if (img->mapp[x] == '\n')
		{
			img->y += 60;
    		img->x = -60;
		}
		if (n==0 && (img->x_p != old_x || img->y_p != old_y))
			mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->x_p, img->y_p);
		else if (n==0 && (img->x_p == old_x || img->y_p == old_y))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->old_plx, img->old_ply);
			img->x_p = img->old_plx;
			img->y_p = img->old_ply;
		}
		x++;
		img->x += 60;
	}
	img->y =0;
	img->x = 0;
}

int key_press(int keycode, t_img *img)
{
	int height = 60;
	int width = 60;
	char *s;
	img->old_plx = img->x_p;
	img->old_ply = img->y_p;
	if (keycode == 123 || keycode == 0)
		img->x_p -= 60;
	else if (keycode == 124 || keycode == 2)
		img->x_p += 60;
	else if (keycode == 125 || keycode == 1)
		img->y_p += 60;
	else if (keycode == 126 || keycode == 13)
		img->y_p -= 60;
	else if (keycode == 53)
		exit(0);
	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->imgb, 0, 0);
    ft_show(img, 0);
	printf("Key pressed: %d\t positon_y  %d\t positon_x  %d\n", keycode, img->y_p, img->x_p);
	return (0);
}

int main(int a, char *av[])
{
	t_img img;
	char *s;

	int i = 0;
	int j = 0;
	int sum = 0;
	img.fd = open("mab.ber", O_RDONLY);
	s = get_next_line(img.fd);
	sum = ft_strlenn(s);
	while (s)
	{
		j = ft_strlenn(s);
		img.mapp = ft_strjoin(img.mapp, s); 
		if(j != sum)
		{
			printf("error -  %d || %d",sum , j);
			return 0;
		}
		i++;
		free(s);
		s = get_next_line(img.fd);
	}
	if(i == j)
	{
		printf("error");
		return 0;
	}
	if(ft_check_map(&img,i,j))
	{
		printf("error -- 1");
		return 0;
	}
	int width = j*60;
	int height = i*60;
	img.x = 0;
	img.y = 0;
	int widthp = 60;
	int heightp = 60;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, width, height, "so_long");
	img.imgb = mlx_xpm_file_to_image(img.mlx, "img/bk.xpm", &width, &height);
	if (!img.imgb)
		return (1);
	mlx_put_image_to_window(img.mlx, img.win, img.imgb, 0, 0);

	img.imgp = mlx_xpm_file_to_image(img.mlx, "img/player.xpm", &widthp, &heightp);
	img.imgc = mlx_xpm_file_to_image(img.mlx, "img/coin.xpm", &widthp, &heightp);
	img.imgw = mlx_xpm_file_to_image(img.mlx, "img/wall.xpm", &widthp, &heightp);
	img.imgd = mlx_xpm_file_to_image(img.mlx, "img/door.xpm", &widthp, &heightp);
	img.imgcd = mlx_xpm_file_to_image(img.mlx, "img/cdoor.xpm", &widthp, &heightp);

	if (!img.imgp || !img.imgc || !img.imgw || !img.imgd || !img.imgcd)
		return (1);
	
	ft_show(&img, 1);
	mlx_hook(img.win, 2, 0, key_press, &img);
	mlx_loop(img.mlx);
	return (0);
}