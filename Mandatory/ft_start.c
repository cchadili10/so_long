/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:02:04 by hchadili          #+#    #+#             */
/*   Updated: 2024/04/03 02:37:50 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_for_des(t_img *img, int x)
{
	if (x == 2)
		mlx_destroy_image(img->mlx, img->imgb);
	else if (x == 3)
	{
		mlx_destroy_image(img->mlx, img->imgb);
		mlx_destroy_image(img->mlx, img->imgp);
	}
	else if (x == 4)
	{
		mlx_destroy_image(img->mlx, img->imgb);
		mlx_destroy_image(img->mlx, img->imgp);
		mlx_destroy_image(img->mlx, img->imgc);
	}
	else if (x == 5)
	{
		mlx_destroy_image(img->mlx, img->imgb);
		mlx_destroy_image(img->mlx, img->imgp);
		mlx_destroy_image(img->mlx, img->imgc);
		mlx_destroy_image(img->mlx, img->imgw);
	}
	((1) && (img->imgb = NULL , img->imgp = NULL, img->imgc = NULL));
	((1) && (img->imgw = NULL , img->imgd = NULL));
	ft_error();
}

void	ft_start(t_img *img, int w_b, int h_b)
{
	int	w;
	int	h;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (w_b * 60), (h_b * 60), "so_long");
	
	img->imgb = mlx_xpm_file_to_image(img->mlx, "Mandatory/img/bk.xpm", &w_b, &h_b);
	if (!img->imgb)
		ft_error();
	img->imgp = mlx_xpm_file_to_image(img->mlx, "Mandatory/img/player.xpm", &w, &h);
	if (!img->imgp)
		ft_for_des(img, 2);
	img->imgc = mlx_xpm_file_to_image(img->mlx, "Mandatory/img/flos.xpm", &w, &h);
	if (!img->imgc)
		ft_for_des(img, 3);
	img->imgw = mlx_xpm_file_to_image(img->mlx, "Mandatory/img/wall.xpm", &w, &h);
	if (!img->imgw)
		ft_for_des(img, 4);
	img->imgd = mlx_xpm_file_to_image(img->mlx, "Mandatory/img/door.xpm", &w, &h);
	if (!img->imgd)
		ft_for_des(img, 5);
}
