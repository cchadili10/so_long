/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:02:04 by hchadili          #+#    #+#             */
/*   Updated: 2024/01/13 13:13:41 by hchadili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_start(t_img *img, int w_b, int h_b)
{
	int	w;
	int	h;

	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, (w_b * 60), (h_b * 60), "so_long");
	img->imgb = mlx_xpm_file_to_image(img->mlx, "img/bk.xpm", &w_b, &h_b);
	img->imgp = mlx_xpm_file_to_image(img->mlx, "img/player.xpm", &w, &h);
	img->imgc = mlx_xpm_file_to_image(img->mlx, "img/flos.xpm", &w, &h);
	img->imgw = mlx_xpm_file_to_image(img->mlx, "img/wall.xpm", &w, &h);
	img->imgd = mlx_xpm_file_to_image(img->mlx, "img/door.xpm", &w, &h);
	img->imgcd = mlx_xpm_file_to_image(img->mlx, "img/cdoor.xpm", &w, &h);
	img->pr = mlx_xpm_file_to_image(img->mlx, "img/pr.xpm", &w, &h);
	img->pu = mlx_xpm_file_to_image(img->mlx, "img/pu.xpm", &w, &h);
	img->pl = mlx_xpm_file_to_image(img->mlx, "img/pl.xpm", &w, &h);
	img->pd = mlx_xpm_file_to_image(img->mlx, "img/pd.xpm", &w, &h);
	img->enmy = mlx_xpm_file_to_image(img->mlx, "img/enmy.xpm", &w, &h);
}
