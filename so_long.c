/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:46:38 by hchadili          #+#    #+#             */
/*   Updated: 2024/01/06 14:51:26 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkis_valid(int position, int pos_player)
{
	if(position <= pos_player && (position + 60) >= pos_player)
		return 1;
	return 0;
}


void ft_show(t_img *img, int n)
{
	int x = 0;
	int old_x;
	int old_y;
	//img->x = 0;
	while (img->mapp[x])
	{
		if (img->mapp[x] == '1')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgw, img->x, img->y);
			printf("x =  %d-- y = %d\n",img->x ,img->y );
			old_x = img->x;
			old_y = img->y;
		}
		else if (img->mapp[x] == 'P' && n)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->x, img->y);
			img->x_p = img->x;
			img->y_p = img->y;
		}
		else if (img->mapp[x] == 'C' && (img->x_p != img->x || img->y_p != img->y))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgc, img->x, img->y);
		}
		else if (img->mapp[x] == 'C' && (img->x_p == img->x && img->y_p== img->y))
		{
			img->mapp[x] = '0';
			//img->x;
		}
		else if (img->mapp[x] == '\n')
		{
			img->y += 60;
    		img->x = -60;
		}
		// else
		// {
		// 	//img->x += 50;
		// 	printf("0");
		// }
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
	//printf("%s-dfgnkfg",img->mapp);
}

int key_press(int keycode, t_img *img)
{
	int height = 60;
	int width = 60;
	char *s;
	img->old_plx = img->x_p;
	img->old_ply = img->y_p;
	if (keycode == 123)
		img->x_p -= 60;
	else if (keycode == 124)
		img->x_p += 60;
	else if (keycode == 125)
		img->y_p += 60;
	else if (keycode == 126)
		img->y_p -= 60;

	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->imgb, 0, 0);
    ft_show(img, 0);
	//printf("Key pressed: %d\t positon_y  %d\t positon_x  %d\n", keycode, img->y_p, img->x_p);
	
	return (0);
}

int main(int a, char *av[])
{
	t_img img;
	char *s;

	int width = 12*60;
	int height = 7*60;
	img.x = 0;
	img.y = 0;
	int widthp = 60;
	int heightp = 60;
	///
	img.fd = open("mab.ber", O_RDONLY);
	while ((s = get_next_line(img.fd)))
		img.mapp = ft_strjoin(img.mapp, s);
	///
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, width, height, "so_long");
	img.imgb = mlx_xpm_file_to_image(img.mlx, "img/bk.xpm", &width, &height);
	if (!img.imgb)
		return (1);

	mlx_put_image_to_window(img.mlx, img.win, img.imgb, 0, 0);

	img.imgp = mlx_xpm_file_to_image(img.mlx, "img/player.xpm", &widthp, &heightp);
	img.imgc = mlx_xpm_file_to_image(img.mlx, "img/coin.xpm", &widthp, &heightp);
	img.imgw = mlx_xpm_file_to_image(img.mlx, "img/wall.xpm", &widthp, &heightp);

	if (!img.imgp || !img.imgc || !img.imgw)
		return (1);
	
	ft_show(&img, 1);
	mlx_hook(img.win, 2, 0, key_press, &img);
	mlx_loop(img.mlx);
	return (0);
}







//// mlx_put_image_to_window(img->mlx,img->win,img->imgb,0,0);
	// mlx_put_image_to_window(img->mlx,img->win,img->imgp,img->x,img->y);
	// if(img->x == 300 && img->y == 500 && img->imgc) {
	//     mlx_destroy_image(img->mlx, img->imgc);
	//     img->imgc = NULL;
	// }
	// if (img->imgc != NULL)
	//     mlx_put_image_to_window(img->mlx,img->win,img->imgc,300,500);
	//