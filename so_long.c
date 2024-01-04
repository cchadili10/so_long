#include "so_long.h"

void ft_show(t_img *img, int n)
{
	int x = 0;
	int p = 0;
	//img->x = 0;
	while (img->mapp[x])
	{
		if (img->mapp[x] == '1')
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgw, img->x, img->y);
			printf("1");
		}
		else if (img->mapp[x] == 'P' && n)
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->x, img->y);
			img->x_p = img->x;
			img->y_p = img->y;
			printf("p");
		}
		else if (img->mapp[x] == 'C' && (img->x_p != img->x || img->y_p != img->y))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->imgc, img->x, img->y);
			printf("C");
		}
		else if (img->mapp[x] == 'C' && (img->x_p == img->x && img->y_p == img->y))
		{
			img->mapp[x] = '0';
			//img->x;
		}
		else if (img->mapp[x] == '\n')
		{
			img->y += 70;
    		img->x = -70;
			printf("\n");
		}
		else
		{
			//img->x += 70;
			printf("0");
		}
		x++;
		img->x += 70;
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
	int old_x = img->x_p;
	int old_y = img->y_p;
	if (keycode == 123)
		img->x_p -= 10;
	else if (keycode == 124)
		img->x_p += 10;
	else if (keycode == 125)
		img->y_p += 10;
	else if (keycode == 126)
		img->y_p -= 10;

	mlx_clear_window(img->mlx, img->win);
	mlx_put_image_to_window(img->mlx, img->win, img->imgb, 0, 0);
	if (old_x != img->x_p || old_y != img->y_p)
	{
		mlx_destroy_image(img->mlx, img->imgp);
		img->imgp = NULL;
		img->imgp = mlx_xpm_file_to_image(img->mlx, "img/player.xpm", &width, &height);
		mlx_put_image_to_window(img->mlx, img->win, img->imgp, img->x_p, img->y_p);
	}
   
    ft_show(img, 0);
	printf("Key pressed: %d\t positon_y  %d\t positon_x  %d\n", keycode, img->y_p, img->x_p);
	
	return (0);
}

int main(int a, char *av[])
{
	t_img img;
	char *s;

	int width = 1000;
	int height = 600;
	img.x = 0;
	img.y = 0;
	int widthp = 10;
	int heightp = 10;
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