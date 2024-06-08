/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:07:52 by hchadili          #+#    #+#             */
/*   Updated: 2024/06/04 07:21:07 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_arr(char **arr)
{
	int	y;

	y = 0;
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
}

void	ft_des_img(t_img *img)
{
	mlx_destroy_image(img->mlx, img->imgb);
	mlx_destroy_image(img->mlx, img->imgp);
	mlx_destroy_image(img->mlx, img->imgc);
	mlx_destroy_image(img->mlx, img->imgw);
	mlx_destroy_image(img->mlx, img->imgd);
	mlx_destroy_image(img->mlx, img->imgcd);
	mlx_destroy_image(img->mlx, img->pr);
	mlx_destroy_image(img->mlx, img->pu);
	mlx_destroy_image(img->mlx, img->pl);
	mlx_destroy_image(img->mlx, img->pd);
	mlx_destroy_image(img->mlx, img->enmy);
	mlx_destroy_window(img->mlx, img->win);
	free(img->mapp);
}

void	ft_setzero(t_img *img)
{
	img->mlx = 0;
	img->win = 0;
	img->imgp = 0;
	img->imgc = 0;
	img->imgw = 0;
	img->imgd = 0;
	img->pr = 0;
	img->pu = 0;
	img->pl = 0;
	img->pd = 0;
	img->mapp = 0;
	img->move = 0;
	img->x = 0;
	img->y = 0;
	img->x_p = 0;
	img->y_p = 0;
	img->fd = 0;
	img->old_plx = 0;
	img->old_ply = 0;
	img->old_key = -1;
	img->col = 0;
	img->size_of_line = 0;
}
